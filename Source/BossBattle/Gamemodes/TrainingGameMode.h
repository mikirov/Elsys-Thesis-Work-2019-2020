// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gamemodes/BossBattleGameMode.h"
#include "TrainingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ATrainingGameMode : public ABossBattleGameMode
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
	void ResetCharacters();

	void BeginPlay() override;

	void DecrementEnemyCounter() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ARLEnemyCharacter> RLEnemyTemplate;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AAIEnemyCharacter> AIEnemyTemplate;	

	class ASpawner* Spawner = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FTransform> InitialTransforms;
};
