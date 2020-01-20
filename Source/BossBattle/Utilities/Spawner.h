// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"


UCLASS()
class BOSSBATTLE_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();


	//Spawn specified number of enemies inside the box component
	void SpawnEnemy(TSubclassOf<class AEnemyCharacter> EnemyTemplate, int Count);

private:

	//Bounding box inside which the enemy spawns
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent = nullptr;

};