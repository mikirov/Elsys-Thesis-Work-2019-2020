// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatsWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UPlayerStatsWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	//widget containing the end game text
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* GameEndText = nullptr;

	//text to show when the playerrs win the game
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FText WinGameText;

	//text to show when the players lose the game
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FText LoseGameText;

	//score
	UFUNCTION()
	void SetScore(int Score);

	//lose game text handler
	void SetLoseGame();

	//win game text handler
	void SetWinGame();

private:


	void NativeConstruct() override;

	//health bar of the current player
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar = nullptr;

	//score of the current team
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ScoreText = nullptr;
};
