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

	if (FirstLevelName.IsNone()) {
		FirstLevelName = FName("Main");
	}
	if (ServerAddress.IsNone()) {
		ServerAddress = FName("127.0.0.1"); // local host
	}

	if (validate(IsValid(StartGameButton))) {
		StartGameButton->OnPressed.AddDynamic(this, &UMainMenuWidget::StartLevel);
	}

	if (validate(IsValid(SettingsButton))) {
		SettingsButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadSettingsMenu);
	}

	if (validate(IsValid(QuitButton))) {
		QuitButton->OnPressed.AddDynamic(this, &UMainMenuWidget::QuitGame);
	}

	if (validate(IsValid(MultiplayerSettingsButton))) {
		MultiplayerSettingsButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadMultiplayerMenu);
	}
	if (validate(IsValid(RLTrainingButton))) {
		RLTrainingButton->OnPressed.AddDynamic(this, &UMainMenuWidget::LoadTrainingMap);
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

void UMainMenuWidget::SetInputModeGameAndUI() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_GameAndUI(PlayerController);

}

void UMainMenuWidget::StartLevel() {
	UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::StartLevel"))
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	//if (validate(FirstLevelName.ToString().Len() > 0) == false) { return; }
	
	//UGameplayStatics::OpenLevel(World, FirstLevelName);
	UGameplayStatics::OpenLevel(World, "127.0.0.1");

	SetInputModeGameOnly();
	//SetInputModeGameAndUI();

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

void UMainMenuWidget::LoadMultiplayerMenu() {
	UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::LoadMultiplayerMenu"))

	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD))) {
		MainMenuHUD->LoadMultiplayerMenu();
	}
}


void UMainMenuWidget::QuitGame() {
	UWorld* World = GetWorld();
	APlayerController* Player = GetOwningPlayer();

	if (validate(IsValid(World)) && validate(IsValid(Player))) {
		UKismetSystemLibrary::QuitGame(World, Player, EQuitPreference::Quit, true);
	}
}

void UMainMenuWidget::LoadTrainingMap() {
	UE_LOG(LogTemp, Warning, TEXT("UMainMenuWidget::LoadTrainingMap"))

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	if (validate(TrainingLevelName.ToString().Len() > 0) == false) { return; }


	SetInputModeGameOnly();

	UGameplayStatics::OpenLevel(World, TrainingLevelName);


}
