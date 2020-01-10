// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseMenuWidget.h"


#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Utilities/CustomMacros.h"

void ULoseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RestartLevelName = FName(TEXT("Main"));

	MainMenuLevelName = FName(TEXT("MainMenu"));

	if (validate(IsValid(RestartGameButton))) {
		RestartGameButton->OnPressed.AddDynamic(this, &ULoseMenuWidget::RestartGame);
	}
	if (validate(IsValid(QuitButton))) {
		QuitButton->OnReleased.AddDynamic(this, &ULoseMenuWidget::QuitGame);
	}
	if (validate(IsValid(MainMenuButton))) {
		MainMenuButton->OnPressed.AddDynamic(this, &ULoseMenuWidget::LoadMainMenu);
	}

}

void ULoseMenuWidget::SetInputModeGameOnly()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
}

void ULoseMenuWidget::QuitGame()
{
	UWorld* World = GetWorld();
	APlayerController* Player = GetOwningPlayer();

	if (validate(IsValid(World)) && validate(IsValid(Player))) {
		UKismetSystemLibrary::QuitGame(World, Player, EQuitPreference::Quit, true);
	}
}

void ULoseMenuWidget::RestartGame()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	//if (validate(RestartLevelName.ToString().Len() > 0) == false) { return; }

	//UGameplayStatics::OpenLevel(World, RestartLevelName);
	UGameplayStatics::OpenLevel(World, "127.0.0.1");
}

void ULoseMenuWidget::LoadMainMenu()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	if (validate(MainMenuLevelName.ToString().Len() > 0) == false) { return; }

	UGameplayStatics::OpenLevel(World, MainMenuLevelName);
}
