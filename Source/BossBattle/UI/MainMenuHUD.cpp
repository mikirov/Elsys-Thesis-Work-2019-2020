// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/SettingsWidget.h"
#include "UI/MainMenuWidget.h"
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

	UWidgetBlueprintLibrary::SetInputMode_UIOnly(PlayerController, MainMenuWidget, false);
}


void AMainMenuHUD::SaveSettings() {
	USettingsSaveGame* SaveGameInstance = Cast<USettingsSaveGame>(
		UGameplayStatics::CreateSaveGameObject(USettingsSaveGame::StaticClass())
	);

	// Dont't use validate. Expected behaviour!
	if (IsValid(SaveGameInstance)) {
		
		UGameplayStatics::SaveGameToSlot(
			SaveGameInstance,
			SaveGameInstance->GetSaveSlotName(),
			SaveGameInstance->GetUserIndex()
		);
	}
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


void AMainMenuHUD::LoadMainMenu() {
	if (validate(IsValid(MainMenuWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	MainMenuWidget = Cast<UMainMenuWidget>(CreateWidget(World, MainMenuWidgetTemplate));
	if (validate(IsValid(MainMenuWidget)) == false) { return; }

	if (IsValid(SettingsWidget)) {
		SettingsWidget->RemoveFromViewport();
	}

	MainMenuWidget->AddToViewport();
}