// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/DataTable.h"
#include "GameFramework/Character.h"

#include "Utilities/SpawnerTable.h"
#include "Utilities/CustomMacros.h"

// Sets default values
ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent = FindComponentByClass<UBoxComponent>();
	validate(IsValid(BoxComponent));
}

void ASpawner::SpawnEnemy(TSubclassOf<ACharacter> EnemyTemplate, int Count) {
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
		ACharacter* Enemy = World->SpawnActor<ACharacter>(
			EnemyTemplate,
			EnemySpawnPosition,
			SpawnParameters);
	}
	/*
	AShooterGameMode* GameMode = Cast<AShooterGameMode>(World->GetAuthGameMode());
	if (validate(IsValid(GameMode)) == false) { continue;; }

	GameMode->IncrementEnemyCounter(Count);

	*/

}


