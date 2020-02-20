// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlayerCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/BattleHUD.h"
#include "UI/ChatWidget.h"
#include "GameModes/BossBattleGameMode.h"
#include "GameModes/PlayingGameMode.h"
#include "UI/PlayerStatsWidget.h"
#include "Characters/PlayerCharacterController.h"
#include "Characters/AIEnemyCharacter.h"
#include "Characters/HealthComponent.h"
#include "Utilities/InputType.h"
#include "Utilities/CustomMacros.h"
#include "Weapons/Gun.h"
#include "Components/EditableTextBox.h"


APlayerCharacter::APlayerCharacter()
{
	// Set size for collision capsule
	UCapsuleComponent* Capsule;
	Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule))) {
		//change if you change the mesh
		Capsule->InitCapsuleSize(42.f, 96.0f);
	}
	
	RotationArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	RotationArrow->SetupAttachment(Capsule);
	// set our turn rates for input

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	
	// Create a spring arm (pulls in towards the player if there is a collision)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	SpringArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	TPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPCamera"));
	TPCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	TPCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	TPCamera->SetActive(true);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void APlayerCharacter::SetChat(class UChatWidget* ChatWidgetToSet) {
	ChatWidget = ChatWidgetToSet;
}


void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (validate(IsValid(PlayerInputComponent)) == false) return;

	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayerCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::ServerInteractWithWeapon);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlayerCharacter::ServerStartReloading);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::ServerStartFiring);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::ServerStopFiring);

	
	PlayerInputComponent->BindAction("OpenChat", IE_Pressed, this, &APlayerCharacter::OpenChat);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::HandleCrouch);

	PlayerInputComponent->BindAction("Close", IE_Pressed, this, &APlayerCharacter::Close);
}

void APlayerCharacter::OpenChat() {
	if (validate(IsValid(ChatWidget)) == false) return;

	ChatWidget->Open();
}




void APlayerCharacter::Close()
{
	UE_LOG(LogTemp, Warning, TEXT(" APlayerCharacter::Close()"))

	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::Die()
{
	Super::Die();

	if (IsLocallyControlled()) {
		APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(GetController());
		if (validate(IsValid(PlayerController)) == false) { return; }

		DisableInput(PlayerController);
	}

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayingGameMode* PlayingGameMode = Cast<APlayingGameMode>(World->GetAuthGameMode());
	if (validate(IsValid(PlayingGameMode)) == false) { return; }

	APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(GetController());
	if (validate(IsValid(PlayerController)) == false) { return; }


	PlayingGameMode->OnPlayerDeath(PlayerController);
}


void APlayerCharacter::OnDeathAnimationEnd()
{
	APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(GetController());
	if (validate(IsValid(PlayerController)) == false) return;
	PlayerController->LoadLoseLevel();
	Super::OnDeathAnimationEnd();
}

void APlayerCharacter::PickGun(AGun* NewGun)
{

	Super::PickGun(NewGun);
	NewGun->OnFire.AddDynamic(this, &APlayerCharacter::PlayCameraShake);
}

void APlayerCharacter::HandleCrouch()
{
	UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
	if (validate(IsValid(CharacterMovementComponent)) == false) return;
	bool bCrouching = CharacterMovementComponent->IsCrouching();

	bCrouching ? UnCrouch() : Crouch();
}

void APlayerCharacter::PlayCameraShake() {
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (validate(IsValid(PlayerController)) == false) { return; }

	if (validate(IsValid(Gun)) == false) { return; }
	TSubclassOf<UCameraShake> GunfireCameraShake = Gun->GetGunfireCameraShake();
	if (validate(IsValid(GunfireCameraShake)) == false) { return; }

	PlayerController->PlayerCameraManager->PlayCameraShake(
		GunfireCameraShake, 1, ECameraAnimPlaySpace::UserDefined, GetControlRotation()
	);

}


void APlayerCharacter::TurnAtRate(float Rate)
{

	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());

}

void APlayerCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
