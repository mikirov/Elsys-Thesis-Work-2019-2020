// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SettingsSaveGame.generated.h"


enum class InputType : uint8;


/**
 * 
 */
UCLASS()
class BOSSBATTLE_API USettingsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	USettingsSaveGame();


	//graphical quality setting index
	UPROPERTY()
	int GraphicalIndex;

	//post processing setting index
	UPROPERTY()
	int PPIndex;

	//main setting index
	UPROPERTY()
	int MainSettings;

	//anti-alliasing settign index
	UPROPERTY()
	int AAIndex;

	//fps setting index
	UPROPERTY()
	int FPSIndex;

	//shadow setting index
	UPROPERTY()
	int ShadownIndex;

	//get the name of the save point
	FString GetSaveSlotName();

	//get index of the user that saved the game
	uint32 GetUserIndex();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	uint32 UserIndex;
};
