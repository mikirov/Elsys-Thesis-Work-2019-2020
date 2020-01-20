// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "TableSaveGame.generated.h"

/**
 * 
 */
USTRUCT()
struct FActionValues
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<float> ActionValues;

	FActionValues()
	{
		ActionValues = TArray<float>();
	}
	FActionValues(TArray<float> ActionValuesToSet) : ActionValues(ActionValuesToSet) {}

};

UCLASS()
class BOSSBATTLE_API UTableSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	
	UTableSaveGame();

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;


	UPROPERTY(VisibleAnywhere, Category = Basic)
	TMap<int, struct FActionValues> QTable;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int Episode;

};
