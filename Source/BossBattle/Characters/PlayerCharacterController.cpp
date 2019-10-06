// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "GameModes/BossBattleGameMode.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"
#include "Utilities/SettingsSaveGame.h"
#include "Utilities/CustomMacros.h"

bool APlayerCharacterController::OnWinGame_Validate() {
	return true;
}


void APlayerCharacterController::OnWinGame_Implementation() {
	
	ABattleHUD* HUD = Cast<ABattleHUD>(GetHUD());
	if (validate(IsValid(HUD)) == false) { return; }

	UPlayerStatsWidget* PlayerStatsWidget = HUD->GetPlayerStatsWidget();

	if (validate(IsValid(PlayerStatsWidget))) {

		PlayerStatsWidget->SetWinGame();
	}
	
}



bool APlayerCharacterController::OnLoseGame_Validate() {
	return true;
}

void APlayerCharacterController::OnLoseGame_Implementation() {
	ABattleHUD* HUD = Cast<ABattleHUD>(GetHUD());
	if (validate(IsValid(HUD)) == false) { return; }

	
	
	UPlayerStatsWidget* PlayerStatsWidget = HUD->GetPlayerStatsWidget();
	
	if (validate(IsValid(PlayerStatsWidget))) {
		PlayerStatsWidget->SetLoseGame();
	}
	
	
}

bool APlayerCharacterController::IsRespawning()
{
	return bRespawning;
}

void APlayerCharacterController::SetRespawning(bool State)
{
	bRespawning = State;
}
