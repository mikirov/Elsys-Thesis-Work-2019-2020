// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LoseMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ALoseMenuHUD : public AHUD
{
	GENERATED_BODY()
protected:
	void PostInitializeComponents() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class ULoseMenuWidget> LoseMenuWidgetTemplate;

	class ULoseMenuWidget* LoseMenuWidget = nullptr;

	void LoadLoseMenuWidget();

};
