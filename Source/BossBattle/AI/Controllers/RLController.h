// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Utilities/TableSaveGame.h"
#include "RLController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLController : public AAIController
{
	GENERATED_BODY()
	
	
protected:

	void BeginPlay();

	void TakeAction(int ActionIndex);

	int GetState();

	void GetBestAction(const int CurrentStateIndex, int& OutCurrentActionIndex, float& OutCurrentActionValue);

	TMap<int, struct FActionValues> QTable; // QTable containing a mapping between each state and a list of all action values

	TArray<class Action*> Actions;


	UPROPERTY(BlueprintReadOnly)
	//index of the current state
	int CurrentStateIndex = 0;

	UPROPERTY(BlueprintReadOnly)
	//index of the previous state
	int PreviousStateIndex = 0;

	UPROPERTY(BlueprintReadOnly)
	//index of the current action
	int CurrentActionIndex = 0;

	UPROPERTY(BlueprintReadOnly)
	//expected reward from the current action
	float CurrentActionValue = 0.0f;

};
