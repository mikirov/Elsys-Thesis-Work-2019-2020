// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


#include "Characters/RLTrainingCharacter.h"
#include "Characters/AIEnemyCharacter.h"
#include "Utilities/Spawner.h"

void ATrainingGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;


	Spawner =  Cast<ASpawner>(UGameplayStatics::GetActorOfClass(World, ASpawner::StaticClass()));
	if (validate(IsValid(Spawner)) == false) return;

	Spawner->SpawnEnemy(RLEnemyTemplate, 1);

	for (FTransform InitialTransform : InitialTransforms) {

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AAIEnemyCharacter* Enemy = World->SpawnActor<AAIEnemyCharacter>(AIEnemyTemplate, InitialTransform, SpawnParameters);
		if (validate(IsValid(Enemy)) == false) return;

	}


}



void ATrainingGameMode::DecrementEnemyCounter()
{
	Super::DecrementEnemyCounter();

	if (AreAllEnemiesDead()) {
		ResetCharacters();
	}
}

void ATrainingGameMode::ResetCharacters() {
	
	UE_LOG(LogTemp, Warning, TEXT("ATrainingGameMode::ResetCharacters"))

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	Spawner->SpawnEnemy(RLEnemyTemplate, 1);

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(World, AAIEnemyCharacter::StaticClass(), OutActors);
	for (auto& Actor : OutActors) {
		AAIEnemyCharacter* AIEnemy = Cast<AAIEnemyCharacter>(Actor);
		AIEnemy->Destroy();
	}

	for (FTransform InitialTransform : InitialTransforms) {

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		World->SpawnActor<AAIEnemyCharacter>(AIEnemyTemplate, InitialTransform, SpawnParameters);

	}
	
	
}