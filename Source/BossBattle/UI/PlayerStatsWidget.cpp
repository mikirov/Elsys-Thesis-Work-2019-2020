// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Containers/UnrealString.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"


#include "Characters/PlayerCharacter.h"
#include "Characters/HealthComponent.h"
#include "UI/BattleHUD.h"
#include "Utilities/CustomMacros.h"

void UPlayerStatsWidget::SetScore(int Score) {
	if (validate(IsValid(ScoreText)) == false) { return; }

	ScoreText->SetText(FText::FromString(FString::FromInt(Score)));
}

void UPlayerStatsWidget::SetLoseGame()
{
	if (validate(IsValid(GameEndText)) == false) { return; }

	if (validate(LoseGameText.ToString() != FString(""))) {
		GameEndText->SetText(LoseGameText);
		GameEndText->SetColorAndOpacity(FSlateColor(FColor::Red));
		GameEndText->SetVisibility(ESlateVisibility::Visible);
	}
}


void UPlayerStatsWidget::SetWinGame()
{
	if (validate(IsValid(GameEndText)) == false) { return; }

	if (validate(WinGameText.ToString() != FString(""))) {
		GameEndText->SetText(WinGameText);
		GameEndText->SetColorAndOpacity(FSlateColor(FColor::Green));
		GameEndText->SetVisibility(ESlateVisibility::Visible);
	}
}


void UPlayerStatsWidget::SetHealth(float Value)
{
	Health = Value;
}

void UPlayerStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (validate(IsValid(GameEndText)) == false) { return; }

	GameEndText->SetVisibility(ESlateVisibility::Collapsed);


}
