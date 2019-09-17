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
	UFUNCTION()
	void SetMaxHealth(float Health);

	UFUNCTION()
	void SetHealth(float Health);

	UFUNCTION()
	void SetScore(int Score);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Health")
	float MaxHealth = 100;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	class UProgressBar* HealthBar = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	class UTextBlock* ScoreText = nullptr;
};
