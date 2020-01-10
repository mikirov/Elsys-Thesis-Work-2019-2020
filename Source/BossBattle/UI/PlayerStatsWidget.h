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

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UTextBlock* GameEndText = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FText WinGameText;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FText LoseGameText;

	UFUNCTION()
	void SetScore(int Score);

	void SetLoseGame();

	void SetWinGame();

protected:


	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UScrollBox* Chat = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UEditableTextBox* InputBox = nullptr;


	void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	class UProgressBar* HealthBar = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	class UTextBlock* ScoreText = nullptr;
};
