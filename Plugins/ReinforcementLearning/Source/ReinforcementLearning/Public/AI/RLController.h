// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RLController.generated.h"

/**
 * 
 */
UCLASS()
class REINFORCEMENTLEARNING_API ARLController : public AAIController
{
	GENERATED_BODY()
	
protected:

	//function called when the controller possesses the RL pawn
	void OnPossess(APawn* InPawn) override;
	
	//taking a certain action
	void TakeAction(int ActionIndex);

	//returns the state of the game as an integer
	virtual int GetState();

	//decides on the best action based on the current state
	void GetBestAction(const int CurrentStateIndex, int& OutCurrentActionIndex, float& OutCurrentActionValue);

	//saves the current Q-table into a file
	void DeserializeTable(float** Table);


	bool bLastActionSuccess = false;


	//loads the Q-table from a file
	void SerializeTable(float** Table);

	//weather or not the controller has already possessed a pawn or not
	bool bPossessed = false;

	//called when the actor is destroyed or the game ends
	void EndPlay
	(
		const EEndPlayReason::Type EndPlayReason
	) override;

	AActor* GetClosestEnemy();


	// QTable containing a mapping between each state and a list of all action values
	float** QTable = nullptr;

	//array of actions that can be taken by the agent
	UPROPERTY(BlueprintReadWrite)
	TArray<class UAction*> Actions;


	//array of states that the environment can give to the agent
	UPROPERTY(BlueprintReadWrite)
	TArray<class UState*> States;


	//index of the current state
	UPROPERTY(BlueprintReadOnly)
	int CurrentStateIndex = 0;


	//index of the previous state
	UPROPERTY(BlueprintReadOnly)
	int PreviousStateIndex = 0;


	//index of the current action
	UPROPERTY(BlueprintReadOnly)
	int CurrentActionIndex = 0;


	//expected reward from the current action
	UPROPERTY(BlueprintReadOnly)
	float CurrentActionValue = 0.0f;

	//frames to wait before performing an action
	UPROPERTY(BlueprintReadOnly)
	int DelayFrames = 2;

	int CurrentFrame = 0;

	UPROPERTY(BlueprintReadOnly)
	float ActionFailReward = -100.0f;

};
