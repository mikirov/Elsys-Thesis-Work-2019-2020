// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:

	void NativeConstruct() override;

	//the name of the weapons showcase map
	UPROPERTY(EditDefaultsOnly)
	FName WeaponsLevelName;

	//start game button
	UPROPERTY(meta = (BindWidget))
	class UButton* StartGameButton = nullptr;

	//settings button
	UPROPERTY(meta = (BindWidget))
	class UButton* SettingsButton = nullptr;
	
	//quit game button
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton = nullptr;
	
	//multiplayer settings button
	UPROPERTY(meta = (BindWidget))
	class UButton* MultiplayerSettingsButton = nullptr;

	//training menu button
	UPROPERTY(meta = (BindWidget))
	class UButton* TrainingButton = nullptr;

	//weapon showcase map button
	UPROPERTY(meta = (BindWidget))
	class UButton* WeaponsButton = nullptr;


	//changes the input mode from UI only to game only
	void SetInputModeGameOnly();

	//loads the weapon showcase level
	UFUNCTION()
	void LoadWeaponsLevel();

	//loads the settings menu
	UFUNCTION()
	void LoadSettingsMenu();

	//loads the multiplayer options menu
	UFUNCTION()
	void LoadGamemodeMenu();

	//quits the game
	UFUNCTION()
	void QuitGame();

	//loads the training settings menu
	UFUNCTION()
	void LoadTrainingWidget();
};
