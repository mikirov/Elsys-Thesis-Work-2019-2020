// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gamemodes/BossBattleGameMode.h"
#include "PlayingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API APlayingGameMode : public ABossBattleGameMode
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// Increments the score by a given amount
	void IncrementScore(const int Amount);

	void DecrementEnemyCounter() override;

	virtual TArray<class APlayerCharacterController*> GetPlayerControllers();

	virtual void OnPlayerDeath(class APlayerCharacterController* PlayerController);

protected:

	virtual void WinGame();

	
	virtual void UpdateHUDScore(int Score);

	int CurrentScore = 0;

	int CurrentEnemies = 0;


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	const class UDataTable* SpawnerLookupTable = nullptr;

	int CurrentWaveIndex = 0;

	UFUNCTION()
	void SpawnEnemyWave();

	int WaveCount = 0;

};
