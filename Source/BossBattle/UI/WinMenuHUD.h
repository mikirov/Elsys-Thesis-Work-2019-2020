// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WinMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AWinMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	void PostInitializeComponents() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UWinMenuWidget> WinMenuWidgetTemplate;

	class UWinMenuWidget* WinMenuWidget = nullptr;

	void LoadWinMenuWidget();
	
};
