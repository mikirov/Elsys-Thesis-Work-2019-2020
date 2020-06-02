// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/ChatHUD.h"

#include "BattleHUD.generated.h"


/**
 * 
 */


UCLASS()
class BOSSBATTLE_API ABattleHUD : public AChatHUD
{
	GENERATED_BODY()

public:

	//player stats widget
	UFUNCTION(BlueprintCallable)
	class UPlayerStatsWidget* GetPlayerStatsWidget();


protected:
	void PostInitializeComponents() override;

	//player stats widget template
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UPlayerStatsWidget> PlayerStatsWidgetTemplate;

	//player stats widget instance
	class UPlayerStatsWidget* PlayerStatsWidget = nullptr;

};
