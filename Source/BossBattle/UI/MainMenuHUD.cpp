// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/SettingsWidget.h"
#include "UI/MainMenuWidget.h"
#include "UI/MultiplayerWidget.h"
#include "UI/TrainingWidget.h"
#include "UI/GamemodeSelectionWidget.h"

#include "Utilities/InputType.h"
#include "Utilities/CustomMacros.h"
#include "Utilities/SettingsSaveGame.h"


void AMainMenuHUD::PostInitializeComponents() {
	Super::PostInitializeComponents();

	LoadMainMenu();
	
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);


	PlayerController->bShowMouseCursor = true;
}


void AMainMenuHUD::LoadSettingsMenu() {
	if (validate(IsValid(SettingsWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	SettingsWidget = Cast<USettingsWidget>(CreateWidget(World, SettingsWidgetTemplate));
	if (validate(IsValid(SettingsWidget)) == false) { return; }

	SettingsWidget->AddToViewport();

	if (IsValid(MainMenuWidget)) {
		MainMenuWidget->RemoveFromViewport();
	}
}

void AMainMenuHUD::LoadMultiplayerMenu() {
	if (validate(IsValid(MultiplayerWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	MultiplayerWidget = Cast<UMultiplayerWidget>(CreateWidget(World, MultiplayerWidgetTemplate));
	if (validate(IsValid(MultiplayerWidget)) == false) { return; }

	MultiplayerWidget->AddToViewport();

	if (IsValid(MainMenuWidget)) {
		MainMenuWidget->RemoveFromViewport();
	}

}


void AMainMenuHUD::LoadTrainingMenu()
{
	if (validate(IsValid(TrainingWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	TrainingWidget = Cast<UTrainingWidget>(CreateWidget(World, TrainingWidgetTemplate));
	if (validate(IsValid(TrainingWidget)) == false) { return; }

	TrainingWidget->AddToViewport();

	if (IsValid(MainMenuWidget)) {
		MainMenuWidget->RemoveFromViewport();
	}

}

void AMainMenuHUD::LoadGamemomeMenu()
{
	if (validate(IsValid(GamemodeWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	GamemodeWidget = Cast<UGamemodeSelectionWidget>(CreateWidget(World, GamemodeWidgetTemplate));
	if (validate(IsValid(GamemodeWidget)) == false) { return; }

	GamemodeWidget->AddToViewport();

	if (IsValid(MainMenuWidget)) {
		MainMenuWidget->RemoveFromViewport();
	}
}

void AMainMenuHUD::LoadMainMenu() {
	if (validate(IsValid(MainMenuWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	MainMenuWidget = Cast<UMainMenuWidget>(CreateWidget(World, MainMenuWidgetTemplate));
	if (validate(IsValid(MainMenuWidget)) == false) { return; }

	if (IsValid(SettingsWidget)) {
		SettingsWidget->RemoveFromViewport();
	}

	if (IsValid(MultiplayerWidget)) {
		MultiplayerWidget->RemoveFromViewport();
	}
	if (IsValid(TrainingWidget)) {
		TrainingWidget->RemoveFromViewport();
	}
	if (IsValid(GamemodeWidget)) {
		GamemodeWidget->RemoveFromViewport();
	}

	MainMenuWidget->AddToViewport();
}