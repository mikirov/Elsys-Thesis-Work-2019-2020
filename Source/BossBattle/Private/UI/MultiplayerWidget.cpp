// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerWidget.h"

#include "Components/Button.h"
#include "Components/VerticalBox.h"

#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"

void UMultiplayerWidget::NativeConstruct() {

	if (validate(IsValid(BackButton))) {
		BackButton->OnPressed.AddDynamic(this, &UMultiplayerWidget::Back);
	}

}

void UMultiplayerWidget::Back() {

	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }

	MainMenuHUD->LoadMainMenu();
}
