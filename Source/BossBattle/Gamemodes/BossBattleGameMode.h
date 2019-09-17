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
	ABossBattleGameMode();

	virtual void BeginPlay() override;

	// Increments the score by a given amount
	UFUNCTION(BlueprintCallable)
	void IncrementScore(const int Amount);

	// Respawns the player to his initial transform
	UFUNCTION()
	virtual void RespawnPlayer(APlayerController* PlayerController);

	UFUNCTION()
	void IncrementEnemyCounter(int EnemyCount);

	UFUNCTION()
	virtual void DecrementEnemyCounter();

	UFUNCTION()
	void RestartLevel();

	UFUNCTION()
	void LoadWinLevel();

protected:

	UFUNCTION()
	virtual void WinGame();

	UFUNCTION()
	virtual void LoseGame();

	UFUNCTION()
	bool AreAllEnemiesDead();

	UFUNCTION()
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

};
