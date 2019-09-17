// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleHUD.h"

#include "UI/PlayerStatsWidget.h"
#include "Utilities/CustomMacros.h"

void ABattleHUD::PostInitializeComponents() {
	Super::PostInitializeComponents();

	if (validate(IsValid(PlayerStatsWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	PlayerStatsWidget = Cast<UPlayerStatsWidget>(CreateWidget(World, PlayerStatsWidgetTemplate));
	if (validate(IsValid(PlayerStatsWidget))) { 
		PlayerStatsWidget->AddToViewport();
	}
}


UPlayerStatsWidget* ABattleHUD::GetPlayerStatsWidget() {
	if (validate(IsValid(PlayerStatsWidget)) == false) { return nullptr;  }

	return PlayerStatsWidget;
}