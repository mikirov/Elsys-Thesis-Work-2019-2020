// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <vector>
#include "RLController.generated.h"
/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLController : public AAIController
{
	GENERATED_BODY()
	
	
protected:

	ARLController();

	//function called when the controller posesses the RL pawn
	void OnPossess(APawn* InPawn) override;

	//taking a certain action
	void TakeAction(int ActionIndex);

	//returns the state of the game as an integer
	int GetState();

	//decides on the best action based on the current state
	void GetBestAction(const int CurrentStateIndex, int& OutCurrentActionIndex, float& OutCurrentActionValue);

	//saves the current Q-table into a file
	void DeserializeTable(float** Table);

	//loads the Q-table from a file
	void SerializeTable(float** Table);

	// QTable containing a mapping between each state and a list of all action values
	float** QTable; 
	
	//array of actions that can be taken by the agent
	std::vector<class Action*> Actions;

	//number of states of the game
	int StateCount = 8; // current number of states


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

};
