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
	UFUNCTION()
	class UPlayerStatsWidget* GetPlayerStatsWidget();

protected:
	void PostInitializeComponents() override;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UPlayerStatsWidget> PlayerStatsWidgetTemplate;

	class UPlayerStatsWidget* PlayerStatsWidget;
};
