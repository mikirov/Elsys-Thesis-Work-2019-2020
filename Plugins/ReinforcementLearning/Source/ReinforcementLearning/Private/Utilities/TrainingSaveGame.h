// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TrainingSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UTrainingSaveGame : public USaveGame
{
	GENERATED_BODY()

	public:
	UTrainingSaveGame();


	//get the name of the save point
	FString GetSaveSlotName();

	//get index of the user that saved the game
	uint32 GetUserIndex();


	//random action chance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Epsilon = 0.01f;

	//discount factor for the future expected rewards
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DiscountFactor = 0.95f;

	//rate at which the action values in the QTable get updated
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float LearningRate = 0.2f;

	//perform an action after every DelayFrames frames
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	int DelayFrames = 2;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float ActionFailReward = -100.0f;



protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	uint32 UserIndex;
	
};
