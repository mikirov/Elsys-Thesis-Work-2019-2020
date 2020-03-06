// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UI/PlayerStatsWidget.h"
#include "UI/ChatWidget.h"
#include "Utilities/CustomMacros.h"
#include "Characters/PlayerCharacter.h"

class UChatWidget* AChatHUD::GetChatWidget()
{
	if (validate(IsValid(ChatWidget)) == false) return nullptr;

	return ChatWidget;
}

void AChatHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	ChatWidget = Cast<UChatWidget>(CreateWidget(World, ChatWidgetTemplate));
	if (validate(IsValid(ChatWidget)) == false) return;
	ChatWidget->AddToViewport();
}

void AChatHUD::DrawHUD()
{
	Super::DrawHUD();

	if (bChatSet == false) {
		APlayerController* PlayerController = GetOwningPlayerController();
		if (validate(IsValid(PlayerController)) == false) return;

		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerController->GetPawn());
		if (validate(IsValid(PlayerCharacter)) == false) return;
		PlayerCharacter->SetChat(ChatWidget);

		bChatSet = true;
	}

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
