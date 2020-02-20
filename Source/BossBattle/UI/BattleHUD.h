// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BattleHUD.generated.h"

/**
 * 
 */


UCLASS()
class BOSSBATTLE_API ABattleHUD : public AHUD
{
	GENERATED_BODY()

public:

	//player stats widget
	UFUNCTION(BlueprintCallable)
	class UPlayerStatsWidget* GetPlayerStatsWidget();

	//chat widget
	UFUNCTION(BlueprintCallable)
	class UChatWidget* GetChatWidget();

protected:
	void PostInitializeComponents() override;

	//player stats widget template
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UPlayerStatsWidget> PlayerStatsWidgetTemplate;
	
	//chat widget template
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UChatWidget> ChatWidgetTemplate;

	//chat widget instance
	class UChatWidget* ChatWidget = nullptr;

	//player stats widget instance
	class UPlayerStatsWidget* PlayerStatsWidget = nullptr;

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	/** Crosshair asset pointer */
	UPROPERTY(EditDefaultsOnly, Category = UI)
	class UTexture2D* CrosshairTex = nullptr;
};
