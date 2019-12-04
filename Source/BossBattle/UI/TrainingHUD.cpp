// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingHUD.h"


#include "UI/TrainingStatsWidget.h"
#include "Utilities/CustomMacros.h"

void ATrainingHUD::PostInitializeComponents() {
	Super::PostInitializeComponents();

	if (validate(IsValid(TrainingStatsWidgetTemplate.Get())) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	TrainingStatsWidget = Cast<UTrainingStatsWidget>(CreateWidget(World, TrainingStatsWidgetTemplate));
	if (validate(IsValid(TrainingStatsWidget))) {
		TrainingStatsWidget->AddToViewport();
	}
}

