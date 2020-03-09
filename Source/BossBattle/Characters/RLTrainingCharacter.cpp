// Fill out your copyright notice in the Description page of Project Settings.


#include "RLTrainingCharacter.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include <limits>
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"

#include "Utilities/CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"
#include "Gamemodes/TrainingGameMode.h"

AActor* ARLTrainingCharacter::GetClosestEnemy()
{
	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingCharacter::GetClosestEnemy()"))
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return nullptr;

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(World, AAIEnemyCharacter::StaticClass(), OutActors);

	float CurrentDistance = std::numeric_limits<float>::max();
	AActor* ChosenActor = nullptr;
	for (AActor* Actor : OutActors) {
		AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(Actor);
		if (validate(IsValid(AICharacter)) == false) return nullptr;

		float DistanceToActor = FVector::Dist(AICharacter->GetActorLocation(), this->GetActorLocation());
		if (DistanceToActor < CurrentDistance) {
			ChosenActor = Actor;
			CurrentDistance = DistanceToActor;
		}
	}

	return ChosenActor;

}



void ARLTrainingCharacter::OnDeathAnimationEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingCharacter::OnDeathAnimationEnd"));
	if (HasAuthority()) {
		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }

		ATrainingGameMode* TrainingGameMode = Cast<ATrainingGameMode>(World->GetAuthGameMode());
		if (validate(IsValid(TrainingGameMode))) {

			FTimerDelegate ResetDelegate;

			ResetDelegate.BindUFunction(TrainingGameMode, FName("ResetCharacters"));
			GetWorldTimerManager().SetTimerForNextTick(ResetDelegate);

			return;
		}
	}
	//Destroy();
	Super::OnDeathAnimationEnd();
}

void ARLTrainingCharacter::Destroyed()
{
	Super::Destroyed();
}

void ARLTrainingCharacter::Die()
{
	Super::Die();
}

