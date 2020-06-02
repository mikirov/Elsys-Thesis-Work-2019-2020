// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ChatHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AChatHUD : public AHUD
{
	GENERATED_BODY()
public:

	//chat widget
	UFUNCTION(BlueprintCallable)
	class UChatWidget* GetChatWidget();

protected:
	void PostInitializeComponents() override;

	//chat widget template
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UChatWidget> ChatWidgetTemplate;

	//chat widget instance
	class UChatWidget* ChatWidget = nullptr;

	/** Primary draw call for the HUD */
	void DrawHUD() override;

	bool bChatSet = false;

	/** Crosshair asset pointer */
	UPROPERTY(EditDefaultsOnly, Category = UI)
	class UTexture2D* CrosshairTex = nullptr;
};
