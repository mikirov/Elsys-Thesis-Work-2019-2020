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


	ChatWidget = Cast<UChatWidget>(CreateWidget(World, ChatWidgetTemplate));
	if (validate(IsValid(ChatWidget)) == false) return;
	ChatWidget->AddToViewport();

	APlayerController* PlayerController = GetOwningPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerController->GetPawn());
	if (validate(IsValid(PlayerCharacter)) == false) return;
	PlayerCharacter->SetChat(ChatWidget);



}

UPlayerStatsWidget* ABattleHUD::GetPlayerStatsWidget() {
	if (validate(IsValid(PlayerStatsWidget)) == false) { return nullptr;  }

	return PlayerStatsWidget;
}

UChatWidget* ABattleHUD::GetChatWidget() {
	if (validate(IsValid(ChatWidget)) == false) return nullptr;

	return ChatWidget;
}

void ABattleHUD::DrawHUD()
{
	Super::DrawHUD();

	if (validate(IsValid(Canvas)) == false) return;
	if (validate(IsValid(CrosshairTex)) == false) return;

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X),
		(Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}
