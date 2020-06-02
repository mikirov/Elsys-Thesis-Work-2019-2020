// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleCharacter.h"
#include "GameFramework/Controller.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/AudioComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "UnrealNetwork.h"
#include "Kismet/KismetSystemLibrary.h"


#include "Animation/CharacterAnimInstance.h"
#include "Characters/HealthComponent.h"
#include "Weapons/Gun.h"
#include "Utilities/CustomMacros.h"


// Sets default values
ABattleCharacter::ABattleCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter()"))
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DeathSoundComponent = CreateDefaultSubobject<UAudioComponent>("DeathSoundAudioComponent");
	DeathSoundComponent->bAutoActivate = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");

	HealthComponent->OnDeath.AddDynamic(this, &ABattleCharacter::Die);
	HealthComponent->SetIsReplicated(true);

	CharacterMovementComponent = Cast<UCharacterMovementComponent>(GetCharacterMovement());
	if (validate(IsValid(CharacterMovementComponent)) == false) return;
	CharacterMovementComponent->GetNavAgentPropertiesRef().bCanCrouch = true;
	CharacterMovementComponent->bCrouchMaintainsBaseLocation = true;
	CharacterMovementComponent->SetIsReplicated(true);


	USkeletalMeshComponent* SkeletalMesh = GetMesh();
	if (validate(IsValid(SkeletalMesh)) == false) { return; }
	
}

bool ABattleCharacter::IsCrouching() {
	return bCrouching;
}

void ABattleCharacter::StartCrouch()
{
	UE_LOG(LogTemp, Warning, TEXT("APlayerCharacter::StartCrouch()"))

		UCapsuleComponent* Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule))) {
		Capsule->SetCapsuleHalfHeight(48.0f);
	}

	bCrouching = true;
	CharacterAnimation->SetCrouching(true);
}

void ABattleCharacter::EndCrouch()
{
	UE_LOG(LogTemp, Warning, TEXT("APlayerCharacter::EndCrouch"))
		UCapsuleComponent* Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule))) {
		Capsule->SetCapsuleHalfHeight(96.0f);
	}


	bCrouching = false;

	CharacterAnimation->SetCrouching(false);

}


// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter()"))
	Super::BeginPlay();

	HealthComponent->OnHealthChanged.AddDynamic(this, &ABattleCharacter::OnTakingDamage);

	CharacterMesh = GetMesh();
	if (validate(IsValid(CharacterMesh)) == false) return;

	CharacterAnimation = Cast<UCharacterAnimInstance>(CharacterMesh->GetAnimInstance());
	validate(IsValid(CharacterAnimation));

	SpawnStartingGun();
	
}


bool ABattleCharacter::IsFiring()
{
	if (validate(IsValid(Gun)) == false) { return false; }
	return Gun->IsFiring();
}

void ABattleCharacter::Move(FVector Direction) {
	AddMovementInput(Direction);
}


FRotator ABattleCharacter::GetAimAtRotation(FVector TargetLocation) {
	
	if (validate(IsValid(Gun)) == false) { return FRotator(0, 0, 0); }

	FVector StartLocation = GetActorLocation();
	StartLocation.Z = Gun->GetActorLocation().Z;

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		StartLocation,
		TargetLocation
	);

	return LookAtRotation;

}


void ABattleCharacter::ServerStopCrouching_Implementation()
{
	MulticastStopCrouching();
}

void ABattleCharacter::OnDeathAnimationEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::OnDeathAnimationEnd"))
	Destroy();
}

void ABattleCharacter::Die()
{
	SetDead(true);
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	if (validate(IsValid(DeathSoundComponent))) {
		DeathSoundComponent->Play();
	}

	if (validate(IsValid(CharacterAnimation))) {
		CharacterAnimation->Die();
	}
	
	
	if (IsFiring()) {
		ServerStopFiring();
	}
}

void ABattleCharacter::Destroyed()
{

	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::Destroyed()"))
	Super::Destroyed();

	if (IsValid(Gun)) {
		Gun->Destroy();
	}
}

void ABattleCharacter::StartFiring() {
	if (validate(IsValid(Gun)) == false) return;
	Gun->PullTrigger();
}


void ABattleCharacter::StopFiring() {
	if (validate(IsValid(Gun)) == false) return;

	Gun->ReleaseTrigger();
}

class UHealthComponent* ABattleCharacter::GetHealthComponent()
{
	return HealthComponent;
}

bool ABattleCharacter::InteractWithWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::InteractWithWeapon"))
	AGun* OldGun = nullptr;
	if (IsValid(Gun)) {
		OldGun = Gun;
	}
	//drop the current gun if you have one
	if (IsValid(Gun)) {
		DropGun();
	}

	//find gun in a sphere around player with given distance
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return false;

	//DrawDebugSphere(World, GetActorLocation(), InteractionDistance, 50, FColor::Yellow, false, 1.0f);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery7);

	TArray<AActor*> OverlappedActors;
	TArray<AActor*> ActorsToIgnore;

	UKismetSystemLibrary::SphereOverlapActors(World, GetActorLocation(), InteractionDistance, ObjectTypes, AGun::StaticClass(), ActorsToIgnore, OverlappedActors);
	if (validate(OverlappedActors.Num() != 0) == false) return false;
	for (auto OverlappedActor : OverlappedActors) {
		
		AGun* NewGun = Cast<AGun>(OverlappedActor);
		if (validate(IsValid(NewGun)) == false) continue;
		if (NewGun == OldGun) continue;

		PickGun(NewGun);
		break;
	}
	return true;
}

void ABattleCharacter::PickGun(class AGun* NewGun)
{
	if (HasAuthority() == false) return;

	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::PickGun(class AGun* NewGun)"))
	if (validate(IsValid(NewGun)) == false) { return; }
	if (validate(IsValid(CharacterMesh)) == false) { return; }
	if (validate(CharacterMesh->DoesSocketExist("GunSocket")) == false) { return; }

	Gun = NewGun;
	
	USkeletalMeshComponent* GunMesh = Gun->FindComponentByClass<USkeletalMeshComponent>();
	if (validate(IsValid(GunMesh)) == false) return;


	Gun->OnPick();

	GunMesh->AttachToComponent(CharacterMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunSocket");
}

void ABattleCharacter::DropGun()
{
	if (HasAuthority() == false) return;

	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::DropGun()"))

	if (validate(IsValid(Gun)) == false) return;

	Gun->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false));

	Gun->OnDrop();
	
	Gun = nullptr;
}

bool ABattleCharacter::StartReloading()
{
	if (bReloadingAllowed == false) { return false; }
	if (validate(IsValid(Gun)) == false) { return false; }

	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::StartReloading"))
	bReloadingAllowed = false;

	CharacterAnimation->SetReloading(true);

	return true;
}

void ABattleCharacter::FinishReloading()
{
	if (validate(IsValid(Gun)) == false) return;


	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::FinishReloading"))

	bReloadingAllowed = true;
	CharacterAnimation->SetReloading(false);
}


void ABattleCharacter::SpawnStartingGun()
{
	if (HasAuthority() == false) return;

	// No validate because player may not have a starting gun.
	if (IsValid(StartingGunTemplate.Get()) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.Instigator = GetInstigator();

	Gun = World->SpawnActor<AGun>(StartingGunTemplate, SpawnInfo);
	PickGun(Gun);
}


void ABattleCharacter::ServerStartFiring_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::ServerStartFiring_Implementation"))
	StartFiring();
}


bool ABattleCharacter::ServerStartFiring_Validate()
{
	return true;
}

void ABattleCharacter::ServerStopFiring_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::ServerStopFiring_Implementation"))
	StopFiring();
}


bool ABattleCharacter::ServerStopFiring_Validate()
{
	return true;
}

void ABattleCharacter::ServerStartReloading_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::ServerStartReloading_Implementation"))
	MulticastStartReloading();


	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABattleCharacter::UpdateGun, 2.16666, false);


	FTimerHandle TimerHandle2;
	GetWorldTimerManager().SetTimer(TimerHandle2, this, &ABattleCharacter::ServerFinishReloading, 2.16666, false);

}

bool ABattleCharacter::ServerStartReloading_Validate()
{
	return true;
}

void ABattleCharacter::ServerFinishReloading_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::ServerFinishReloading_Implementation"));
	MulticastFinishReloading();
}

bool ABattleCharacter::ServerFinishReloading_Validate()
{
	return true;
}

void ABattleCharacter::MulticastStartReloading_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::MulticastStartReloading_Implementation"))
	StartReloading();
}

void ABattleCharacter::MulticastStartCrouching_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::MulticastStartCrouching_Implementation"))

	StartCrouch();
}

void ABattleCharacter::MulticastStopCrouching_Implementation()
{

	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::MulticastStopCrouching_Implementation"))
	EndCrouch();
}

bool ABattleCharacter::MulticastStopCrouching_Validate()
{
	return true;
}

bool ABattleCharacter::MulticastStartCrouching_Validate()
{
	return true;
}

bool ABattleCharacter::MulticastStartReloading_Validate() {
	return true;
}


void ABattleCharacter::MulticastFinishReloading_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::MulticastFinishReloading_Implementation"))
	FinishReloading();
}

void ABattleCharacter::OnTakingDamage(float Amount)
{
	SetTakingDamage(true);
	SetCriticalHealth((HealthComponent->GetHealth() < HealthComponent->GetMaxHealth() / 3));

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABattleCharacter::ClearTakingDamage, 0.0f, false, 0.25f);
}

void ABattleCharacter::ClearTakingDamage()
{
	SetTakingDamage(false);
}

void ABattleCharacter::UpdateGun()
{
	if (validate(IsValid(Gun)) == false) return;
	if (HasAuthority() == false) return;
	Gun->FinishReload();

}

bool ABattleCharacter::MulticastFinishReloading_Validate()
{
	return true;
}

void ABattleCharacter::ServerInteractWithWeapon_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::ServerInteractWithWeapon_Implementation"))
	InteractWithWeapon();
}


bool ABattleCharacter::ServerStartCrouching_Validate()
{
	return true;
}

void ABattleCharacter::ServerStartCrouching_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABattleCharacter::ServerStartCrouching_Implementation"))
	MulticastStartCrouching();
}

bool ABattleCharacter::ServerStopCrouching_Validate()
{
	return true;
}

bool ABattleCharacter::ServerInteractWithWeapon_Validate()
{
	return true;
}