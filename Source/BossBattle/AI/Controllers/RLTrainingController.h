// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Controllers/RLController.h"

#include "RLTrainingController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLTrainingController : public ARLController
{
	GENERATED_BODY()
	
protected:

	void UpdateStepAndEpisode();

	//counter for the current number of steps taken this episode
	int StepsThisEpisode = 0;

	// number of steps before updating the episode
	int StepsPerEpisode = 1000;

	// episode number
	int Episode = 0;

	float GetReward();

	void BeginPlay();

	void Tick(float DeltaTime);

	void ShowTable();

	void SaveTable(int Episode);

	void OnTableSaved(const FString& SlotName, const int32 UserIndex, bool bSuccess);

	TArray<bool> StateArray; // array of boolean flags given as state

	int StateCount = 3; // current number of states

	float CurrentReward = 0.0f; //reward this tick

	//index of the previous action taken
	int PreviousActionIndex = 0;

	// is the RL character hitting the AI character?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bDealingDamage = false;

	//reward the character receives for killing the enemy
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float KillReward = 1.0f;

	//reward the character receives for dying
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DeathReward = -1.0f;

	//reward for dealing damage to the enemy
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DealingDamageReward = 0.1f;

	//reward for taking damage
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float TakingDamageReward = -0.1f;

	//random action chance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Epsilon = 0.1f;

	//whether or not the character should take a random action
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	bool bRandomAction = false;

	//UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	//float NextStateActionValue = 0.0f;

	//discount factor for the future expected rewards
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DiscountFactor = 0.95f;

	//rate at which the action values in the QTable get updated
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float LearningRate = 0.1f;
};
