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

	void OnPlayerDeath(class APlayerCharacterController* PlayerController);

	TArray<class APlayerCharacterController*> GetPlayerControllers();


protected:



	virtual void PostLogin(class APlayerController* PlayerController);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MaxPlayersCount = 4;

	bool bPlaying = false;

	virtual void WinGame();

	
	void UpdateHUDScore(int Score);

	int CurrentScore = 0;

	int CurrentEnemies = 0;

	UPROPERTY(BlueprintReadWrite)
	TArray<class APlayerCharacterController*> PlayerControllers;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	const class UDataTable* SpawnerLookupTable = nullptr;

	int CurrentWaveIndex = 0;

	UFUNCTION()
	void SpawnEnemyWave();

	int WaveCount = 0;

};
