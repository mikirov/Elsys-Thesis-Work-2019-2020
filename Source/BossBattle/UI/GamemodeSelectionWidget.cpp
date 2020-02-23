// Fill out your copyright notice in the Description page of Project Settings.


#include "GamemodeSelectionWidget.h"


#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"

void UGamemodeSelectionWidget::SetInputModeGameOnly()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
}

void UGamemodeSelectionWidget::NativeConstruct()
{

	if (ServerAddress.IsNone()) {
		ServerAddress = FName("127.0.0.1"); // local host
	}
	if (validate(IsValid(SingleplayerButton))) {
		SingleplayerButton->OnPressed.AddDynamic(this, &UGamemodeSelectionWidget::LoadSingleplayer);
	}
	if (validate(IsValid(MultiplayerButton))) {
		MultiplayerButton->OnPressed.AddDynamic(this, &UGamemodeSelectionWidget::LoadMultiplayer);
	}
	if (validate(IsValid(BackButton))) {
		BackButton->OnPressed.AddDynamic(this, &UGamemodeSelectionWidget::Back);
	}
}

void UGamemodeSelectionWidget::Back()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }

	MainMenuHUD->LoadMainMenu();
}

void UGamemodeSelectionWidget::LoadSingleplayer()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	if (validate(SingleplayerMapName.ToString().Len() > 0) == false) { return; }


	SetInputModeGameOnly();
	UGameplayStatics::OpenLevel(World, SingleplayerMapName);
}

void UGamemodeSelectionWidget::LoadMultiplayer()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	SetInputModeGameOnly();

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	//multiplayer joins local server @ 127.0.0.1
	PlayerController->ClientTravel("127.0.0.1", ETravelType::TRAVEL_Absolute, true);
}
