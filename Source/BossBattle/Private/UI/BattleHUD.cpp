// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/PlayerStatsWidget.h"
#include "UI/ChatWidget.h"
#include "Utilities/CustomMacros.h"
#include "Characters/PlayerCharacter.h"

void ABattleHUD::PostInitializeComponents() {
	Super::PostInitializeComponents();

	if (validate(IsValid(PlayerStatsWidgetTemplate.Get())) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	PlayerStatsWidget = Cast<UPlayerStatsWidget>(CreateWidget(World, PlayerStatsWidgetTemplate));
	if (validate(IsValid(PlayerStatsWidget)) == false) return;
	PlayerStatsWidget->AddToViewport();


}

UPlayerStatsWidget* ABattleHUD::GetPlayerStatsWidget() {
	if (validate(IsValid(PlayerStatsWidget)) == false) { return nullptr;  }

	return PlayerStatsWidget;
}