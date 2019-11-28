// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerWidget.h"

#include "Components/Button.h"
#include "Components/VerticalBox.h"

#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"

void UMultiplayerWidget::NativeConstruct() {
	
	if (validate(IsValid(CreateServerMenuButton))) {
		CreateServerMenuButton->OnPressed.AddDynamic(this, &UMultiplayerWidget::OpenCreateServerBox);
	}
	if (validate(IsValid(FindServerMenuButton))) {
		FindServerMenuButton->OnPressed.AddDynamic(this, &UMultiplayerWidget::OpenFindServerBox);
	}
	if (validate(IsValid(JoinServerMenuButton))) {
		JoinServerMenuButton->OnPressed.AddDynamic(this, &UMultiplayerWidget::OpenJoinServerBox);
	}
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

void UMultiplayerWidget::OpenFindServerBox() {
	if(validate(IsValid(CreateServerBox)) == false) return;
	if(validate(IsValid(FindServerBox)) == false) return;
	if(validate(IsValid(JoinServerBox)) == false) return;

	CreateServerBox->SetVisibility(ESlateVisibility::Collapsed);
	FindServerBox->SetVisibility(ESlateVisibility::Visible);
	JoinServerBox->SetVisibility(ESlateVisibility::Collapsed);
}

void UMultiplayerWidget::OpenJoinServerBox() {
	if (validate(IsValid(CreateServerBox)) == false) return;
	if (validate(IsValid(FindServerBox)) == false) return;
	if (validate(IsValid(JoinServerBox)) == false) return;


	CreateServerBox->SetVisibility(ESlateVisibility::Collapsed);
	FindServerBox->SetVisibility(ESlateVisibility::Collapsed);
	JoinServerBox->SetVisibility(ESlateVisibility::Visible);
}
void UMultiplayerWidget::OpenCreateServerBox() {
	if (validate(IsValid(CreateServerBox)) == false) return;
	if (validate(IsValid(FindServerBox)) == false) return;
	if (validate(IsValid(JoinServerBox)) == false) return;

	CreateServerBox->SetVisibility(ESlateVisibility::Visible);
	FindServerBox->SetVisibility(ESlateVisibility::Collapsed);
	JoinServerBox->SetVisibility(ESlateVisibility::Collapsed);
}

