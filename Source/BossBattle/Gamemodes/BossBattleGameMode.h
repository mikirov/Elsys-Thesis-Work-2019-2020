// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BossBattleGameMode.generated.h"

/**
 * 
 */

UCLASS()
class BOSSBATTLE_API ABossBattleGameMode : public AGameModeBase
{

	GENERATED_BODY()
public:
	
	virtual void BeginPlay() override;

	// Increments the score by a given amount
	void IncrementScore(const int Amount);

	// Respawns the player to his initial transform
	virtual void RespawnPlayer(APlayerController* PlayerController);

	void IncrementEnemyCounter(int EnemyCount);

	void DecrementEnemyCounter();

	void RestartLevel();

	void LoadWinLevel();

protected:

	virtual void WinGame();

	virtual void LoseGame();

	bool AreAllEnemiesDead();

	void UpdateHUDScore(int Score);

	void FindPlayerControllers();

	UPROPERTY(EditDefaultsOnly)
	FString MapsFolderPath;

	UPROPERTY(EditDefaultsOnly)
	FString WinGameLevelName;

	UPROPERTY()
	TSubclassOf<class APlayerCharacter> PlayerTemplate;

	int CurrentScore = 0;

	int CurrentEnemies = 0;

	UPROPERTY()
	TArray<class APlayerCharacterController*> PlayerControllers;


	class ATriggerBox* RespawnBox = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	const class UDataTable* SpawnerLookupTable = nullptr;

	int CurrentWaveIndex = 0;

	UFUNCTION()
	void SpawnEnemyWave();

	int WaveCount = 0;

};
