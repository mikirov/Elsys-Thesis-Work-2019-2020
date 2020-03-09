
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TrainingSaveGame.generated.h"



/**
 *
 */
UCLASS()
class BOSSBATTLE_API UTrainingSaveGame : public USaveGame
{
	GENERATED_BODY()

	public:
	UTrainingSaveGame();


	//get the name of the save point
	FString GetSaveSlotName();

	//get index of the user that saved the game
	uint32 GetUserIndex();

	//reward the character receives for killing the enemy
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float KillReward = 1.0f;

	//reward the character receives for dying
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DeathReward = -1.0f;

	//reward for dealing damage to the enemy
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DealingDamageReward = 0.5f;

	//reward for taking damage
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float TakingDamageReward = -0.5f;

	//reward for dealing damage to the enemy
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float AliveReward = 0.5f;

	//random action chance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Epsilon = 0.25f;

	//discount factor for the future expected rewards
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DiscountFactor = 0.95f;

	//rate at which the action values in the QTable get updated
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float LearningRate = 0.2f;

	//multiplier
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float CriticalHealthRewardMultiplier = 3;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	uint32 UserIndex;
};