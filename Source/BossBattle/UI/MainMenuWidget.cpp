// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Components/EditableTextBox.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/SettingsWidget.h"
#include "UI/MainMenuHUD.h"
#include "Utilities/CustomMacros.h"



void UMainMenuWidget::NativeConstruct() {
	Super::NativeConstruct();

	if (validate(IsValid(StartGameButton))) {
		StartGameButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadGamemodeMenu);
	}

	if (validate(IsValid(SettingsButton))) {
		SettingsButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadSettingsMenu);
	}

	if (validate(IsValid(QuitButton))) {
		QuitButton->OnPressed.AddDynamic(this, &UMainMenuWidget::QuitGame);
	}

	if (validate(IsValid(TrainingButton))) {
		TrainingButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadTrainingWidget);
	}
	if (validate(IsValid(WeaponsButton))) {
		WeaponsButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadWeaponsLevel);
	}
}

void UMainMenuWidget::SetInputModeGameOnly()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
}

void UMainMenuWidget::LoadWeaponsLevel()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	if (validate(WeaponsLevelName.ToString().Len() > 0) == false) { return; }


	SetInputModeGameOnly();
	UGameplayStatics::OpenLevel(World, WeaponsLevelName);

}

void UMainMenuWidget::LoadGamemodeMenu() {

	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD))) {
		MainMenuHUD->LoadGamemomeMenu();
	}
}




void UMainMenuWidget::LoadSettingsMenu() {

	UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::LoadSettingsMenu"))
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD))) {
		MainMenuHUD->LoadSettingsMenu();
	}
}


void UMainMenuWidget::QuitGame() {
	UWorld* World = GetWorld();
	APlayerController* Player = GetOwningPlayer();

	if (validate(IsValid(World)) && validate(IsValid(Player))) {
		UKismetSystemLibrary::QuitGame(World, Player, EQuitPreference::Quit, true);
	}
}

void UMainMenuWidget::LoadTrainingWidget() {
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }

	MainMenuHUD->LoadTrainingMenu();

}
