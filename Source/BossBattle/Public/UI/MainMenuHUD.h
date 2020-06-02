// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"



/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	//loads the main menu
	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();

	//loads the settings menu
	void LoadSettingsMenu();

	//loads the multiplayer settings menu
	void LoadMultiplayerMenu();

	//loads the training menu
	void LoadTrainingMenu();

	//loads the gamemode selection menu
	void LoadGamemomeMenu();

protected:

	void PostInitializeComponents() override;

	//main menu widget template
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UMainMenuWidget> MainMenuWidgetTemplate;

	//settings menu widget template
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class USettingsWidget> SettingsWidgetTemplate;
	
	//multiplayer menu widget template
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UMultiplayerWidget> MultiplayerWidgetTemplate;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FName TrainingLevelName;

	//gamemode menu widget template
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UGamemodeSelectionWidget> GamemodeWidgetTemplate;

	//gamemode menu instance
	class UGamemodeSelectionWidget* GamemodeWidget = nullptr;

	//main menu wiwdget instance
	class UMainMenuWidget* MainMenuWidget = nullptr;

	//settings widget instance
	class USettingsWidget* SettingsWidget = nullptr;

	//multiplayer widget instance
	class UMultiplayerWidget* MultiplayerWidget = nullptr;

	//training widget instance
	class UTrainingWidget* TrainingWidget = nullptr;
};