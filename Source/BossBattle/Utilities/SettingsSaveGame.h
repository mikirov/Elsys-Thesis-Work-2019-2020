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

	//type of input device used to play the game
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	InputType Type;

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
