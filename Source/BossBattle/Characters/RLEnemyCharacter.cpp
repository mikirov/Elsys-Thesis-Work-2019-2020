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
#include "AI/Controllers/RLController.h"
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


void ARLEnemyCharacter::FocusOnEnemy() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	

	AActor* OtherCharacter = GetClosestEnemy();
	if(validate(IsValid(OtherCharacter) == false)) return;

	ARLController* RLController = Cast<ARLController>(GetController());

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		GetActorLocation(),
		OtherCharacter->GetActorLocation()
	);

	SetActorRotation(FRotator(0, LookAtRotation.Yaw, 0));

	RLController->SetControlRotation(FRotator(0, LookAtRotation.Yaw, 0));
}

void ARLEnemyCharacter::Die()
{
	Super::Die();
}

AActor* ARLEnemyCharacter::GetClosestEnemy()
{
	return nullptr;
}

