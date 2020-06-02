// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingHUD.h"

#include "TrainingStatsWidget.h"
#include "Utilities/CustomMacros.h"

#include "Blueprint/WidgetBlueprintLibrary.h"

void ATrainingHUD::PostInitializeComponents() {
	Super::PostInitializeComponents();

	if (validate(IsValid(TrainingStatsWidgetTemplate.Get())) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	SetTrainingStatsWidget(Cast<UTrainingStatsWidget>(CreateWidget(World, TrainingStatsWidgetTemplate)));
	if (validate(IsValid(GetTrainingStatsWidget()))) {
		GetTrainingStatsWidget()->AddToViewport();
	}

	APlayerController* PlayerController = GetOwningPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	PlayerController->bShowMouseCursor = true;

	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);

}