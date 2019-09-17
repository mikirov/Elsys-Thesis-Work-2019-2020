// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "GameModes/BossBattleGameMode.h"
#include "UI/BattleHUD.h"
#include "Utilities/SettingsSaveGame.h"
#include "Utilities/CustomMacros.h"

bool APlayerCharacterController::OnWinGame_Validate() {
	return true;
}


void APlayerCharacterController::OnWinGame_Implementation() {
	
	ABattleHUD* HUD = Cast<ABattleHUD>(GetHUD());
	if (validate(IsValid(HUD)) == false) { return; }

	/*
	UNexusDefenceStatsWidget * NexusStatsWidget = NexusDefenceHUD->GetNexusDefenceWidget();
	if (validate(IsValid(NexusStatsWidget))) {
		NexusStatsWidget->SetWinGame();
	}
	*/
	
}



bool APlayerCharacterController::OnLoseGame_Validate() {
	return true;
}

void APlayerCharacterController::OnLoseGame_Implementation() {
	ABattleHUD* HUD = Cast<ABattleHUD>(GetHUD());
	if (validate(IsValid(HUD)) == false) { return; }

	/*
	
	UNexusDefenceStatsWidget * NexusStatsWidget = NexusDefenceHUD->GetNexusDefenceWidget();
	if (validate(IsValid(NexusStatsWidget))) {
		NexusStatsWidget->SetLoseGame();
	}
	*/
	
}