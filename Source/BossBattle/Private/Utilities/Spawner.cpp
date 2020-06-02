// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/DataTable.h"

#include "Gamemodes/BossBattleGameMode.h"
#include "Utilities/SpawnerTable.h"
#include "Utilities/CustomMacros.h"

// Sets default values
ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	if (validate(IsValid(BoxComponent)) == false) return;
}


void ASpawner::SpawnEnemy(TSubclassOf<APawn> EnemyTemplate, int Count) {
	if (validate(IsValid(BoxComponent))  == false) { return; }
	if (validate(IsValid(EnemyTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }


	for (int i = 0; i < Count; i++) {
		//Get random point inside the bounding box
		FVector ActorLocation = GetActorLocation();
		FVector BoxExtent = BoxComponent->GetScaledBoxExtent();
		FTransform EnemySpawnPosition = FTransform(
			UKismetMathLibrary::RandomPointInBoundingBox(
				ActorLocation,
				BoxExtent
			)
		);

		//spawn enemy on the given point
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		APawn* Enemy = World->SpawnActor<APawn>(
			EnemyTemplate,
			EnemySpawnPosition,
			SpawnParameters);
	}

	ABossBattleGameMode* GameMode = Cast<ABossBattleGameMode>(World->GetAuthGameMode());
	if (IsValid(GameMode)) {
		GameMode->IncrementEnemyCounter(Count);
	}

}


