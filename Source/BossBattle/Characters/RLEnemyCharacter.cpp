// Fill out your copyright notice in the Description page of Project Settings.


#include "RLEnemyCharacter.h"

#include "TimerManager.h"
#include "Engine/World.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Characters/HealthComponent.h"
#include "Gamemodes/TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"
#include "AI/Controllers/EnemyAIController.h"

void ARLEnemyCharacter::Reset() {

	SetActorTransform(InitialTransform);
	HealthComponent->ResetHealth();

	ServerStopFiring();

	bDead = false;

}


void ARLEnemyCharacter::MoveForward(float Value)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, 1.0f);
	}
}

void ARLEnemyCharacter::MoveRight(float Value)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ARLEnemyCharacter::BeginPlay() {
	Super::BeginPlay();

	InitialTransform = GetActorTransform();

	HealthComponent->OnHealthChanged.AddDynamic(this, &ARLEnemyCharacter::OnHealthChanged);
	
}

void ARLEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TODO: get dealing damage flag

	//TODO: call python neural network and give it the 3 flags as input

	//TOOD: get result from NN and take action

	//CurrentAction = some_result
	bRandomAction = FMath::RandRange(0.0f, 1.0f) < Epsilon;

	if (bRandomAction) {
		CurrentAction = FMath::RandRange(0, 5);
	}
	else {

	}

	switch (CurrentAction)
	{
	case 0:
		MoveForward(1.0f);
		break;
	case 1:
		MoveForward(-1.0f);
		break;
	case 2:
		MoveRight(1.0f);
		break;
	case 3:

		MoveRight(-1.0f);
		break;
	case 4:
		FocusOnAICharacter();
		break;
	case 5:
		ShootAICharacter();

	default:
		break;
	}

}

void ARLEnemyCharacter::OnHealthChanged(int CurrentHealth) {

	
	bTakingDamage = true;
	bCriticalHealth = (CurrentHealth < HealthComponent->GetMaxHealth() / 3);
	

	//TODO: make sure bDead is actually working as expected
	if (bDead == false) {

		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ARLEnemyCharacter::ClearTakingDamage, 0.0f, false, 0.25f);

	}

}

void ARLEnemyCharacter::ShootAICharacter() {
	//focus on AI character
	FocusOnAICharacter();

	//Move near AI character
	MoveNearAICharacter();

	//Shoot Weapon
	ServerStartFiring();


}

void ARLEnemyCharacter::MoveNearAICharacter() {

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	AActor* AICharacter = UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass());

	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(World);
	if (validate(IsValid(NavigationSystem)) == false) return;

	//FVector Result = NavigationSystem->GetRandomPointInNavigableRadius(World, AICharacter->GetActorLocation(), 600);
	FNavLocation Result;
	NavigationSystem->GetRandomPointInNavigableRadius(AICharacter->GetActorLocation(), 600, Result);
	
	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	AIController->MoveToLocation(Result);
	

}

void ARLEnemyCharacter::FocusOnAICharacter() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	
	AActor* AICharacter = UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass());
	if(validate(IsValid(AICharacter) == false)) return;

	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	//AIController->SetFocus(AICharacter);

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		GetActorLocation(),
		AICharacter->GetActorLocation()
	);

	AICharacter->SetActorRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));

	AIController->SetControlRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));
}

void ARLEnemyCharacter::ClearTakingDamage() {
	bTakingDamage = false;
}


void ARLEnemyCharacter::Die() {
	Super::Die();

	bDead = true;

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	ATrainingGameMode* TrainingGameMode = Cast<ATrainingGameMode>(World->GetAuthGameMode());
	if (validate(IsValid(TrainingGameMode))) {

		TrainingGameMode->ResetCharacters(false);
		return;
	}

}
