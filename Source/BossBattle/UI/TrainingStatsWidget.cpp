// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingStatsWidget.h"


#include "Components/Button.h"

#include "AI/Controllers/RLTrainingController.h"
#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"

void UTrainingStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (validate(IsValid(BackButton))) {
		BackButton->OnClicked.AddDynamic(this, &UTrainingStatsWidget::Back);
	}
	if (validate(IsValid(ResetButton))) {
		ResetButton->OnClicked.AddDynamic(this, &UTrainingStatsWidget::Reset);
	}
}

void UTrainingStatsWidget::Back()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }

	MainMenuHUD->LoadMainMenu();
}

void UTrainingStatsWidget::Reset()
{
	ARLTrainingController* TrainingController = Cast<ARLTrainingController>(GetOwningPlayer());
	if (validate(IsValid(TrainingController)) == false) return;
	TrainingController->ResetTable();
}
