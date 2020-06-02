// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingStatsWidget.h"


#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

#include "RLTrainingController.h"
#include "Utilities/CustomMacros.h"

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
	UWorld* World = GetWorld();
	APlayerController* Player = GetOwningPlayer();

	if (validate(IsValid(World)) && validate(IsValid(Player))) {
		UKismetSystemLibrary::QuitGame(World, Player, EQuitPreference::Quit, true);
	}

}

void UTrainingStatsWidget::Reset()
{
	ARLTrainingController* TrainingController = Cast<ARLTrainingController>(GetOwningPlayer());
	if (validate(IsValid(TrainingController)) == false) return;
	TrainingController->ResetTable();
}
