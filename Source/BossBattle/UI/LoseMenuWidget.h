// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ULoseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	
protected:

	void NativeConstruct() override;

	//name of the map to be loaded as restart level
	UPROPERTY(EditDefaultsOnly)
	FName RestartLevelName;

	//name of the main menu map
	UPROPERTY(EditDefaultsOnly)
	FName MainMenuLevelName;

	//quit button
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton = nullptr;

	//restart button
	UPROPERTY(meta = (BindWidget))
	class UButton* RestartGameButton = nullptr;

	//main menu button
	UPROPERTY(meta = (BindWidget))
	class UButton* MainMenuButton = nullptr;

	//change the input mode from UI to game only
	void SetInputModeGameOnly();

	//quits the game
	UFUNCTION()
	void QuitGame();

	//restarts the game using RestartLevelName
	UFUNCTION()
	void RestartGame();

	//loads the main menu
	UFUNCTION()
	void LoadMainMenu();

};
