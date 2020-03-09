// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingStatsWidget.h"


#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"


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

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	UGameplayStatics::OpenLevel(World, "MainMenu");
}

void UTrainingStatsWidget::Reset()
{
	ARLTrainingController* TrainingController = Cast<ARLTrainingController>(GetOwningPlayer());
	if (validate(IsValid(TrainingController)) == false) return;
	TrainingController->ResetTable();
}
