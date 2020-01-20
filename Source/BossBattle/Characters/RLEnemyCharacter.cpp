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
#include "TimerManager.h"


#include "Gamemodes/TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"
#include "AI/Controllers/EnemyAIController.h"
#include "Utilities/Spawner.h"

void ARLEnemyCharacter::MoveForward(float Value)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
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


void ARLEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ARLEnemyCharacter::ShootEnemy() {
	//focus on AI character
	FocusOnEnemy();

	//Move near AI character
	MoveNearEnemy();

	//Shoot Weapon
	ServerStartFiring();


}

void ARLEnemyCharacter::MoveNearEnemy() {
	
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	AActor* AICharacter = GetClosestEnemy();

	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(World);
	if (validate(IsValid(NavigationSystem)) == false) return;

	//FVector Result = NavigationSystem->GetRandomPointInNavigableRadius(World, AICharacter->GetActorLocation(), 600);
	FNavLocation Result;
	NavigationSystem->GetRandomPointInNavigableRadius(AICharacter->GetActorLocation(), 600, Result);
	
	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	AIController->MoveToLocation(Result);

}


void ARLEnemyCharacter::FocusOnEnemy() {
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

	AICharacter->SetActorRotation(FRotator(0, LookAtRotation.Yaw, 0));

	AIController->SetControlRotation(FRotator(0, LookAtRotation.Yaw, 0));
}

void ARLEnemyCharacter::Die()
{
	Super::Die();
}

AActor* ARLEnemyCharacter::GetClosestEnemy()
{
	return nullptr;
}

