// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Containers/UnrealString.h"

#include "Utilities/CustomMacros.h"

void UPlayerStatsWidget::SetMaxHealth(float Health) {
	MaxHealth = Health;
}

void UPlayerStatsWidget::SetHealth(float Health) {
	if (validate(IsValid(HealthBar)) == false) { return; }

	HealthBar->SetPercent((float)(Health / MaxHealth));
}


void UPlayerStatsWidget::SetScore(int Score) {
	if (validate(IsValid(ScoreText)) == false) { return; }

	ScoreText->SetText(FText::FromString(FString::FromInt(Score)));
}