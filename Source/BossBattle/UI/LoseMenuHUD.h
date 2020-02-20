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

	//lose menu widget template
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class ULoseMenuWidget> LoseMenuWidgetTemplate;

	//lose menu widget instance
	class ULoseMenuWidget* LoseMenuWidget = nullptr;

	//loads the lose menu
	void LoadLoseMenuWidget();

};
