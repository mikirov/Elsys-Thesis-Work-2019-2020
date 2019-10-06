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
	void LoadMainMenu();

	void LoadSettingsMenu();

	UFUNCTION(BlueprintCallable)
	void SaveSettings();

protected:

	void PostInitializeComponents() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UMainMenuWidget> MainMenuWidgetTemplate;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class USettingsWidget> SettingsWidgetTemplate;

	class UUserWidget* MainMenuWidget = nullptr;

	class USettingsWidget* SettingsWidget = nullptr;
};