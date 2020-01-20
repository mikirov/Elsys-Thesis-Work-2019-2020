// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"

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

	FTimerHandle RespawnTimerHandle; // not used anywhere
	GetWorldTimerManager().SetTimer(
		RespawnTimerHandle,
		this,
		&APlayerCharacterController::LoadWinLevel,
		LoadEndLevelDelay
	);
	
}

void APlayerCharacterController::LoadWinLevel() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	validate(MapsFolderPath.Len() > 0);

	if (validate(WinGameLevelName.Len() > 0) == false) { return; }

	World->ServerTravel(MapsFolderPath + WinGameLevelName, true);
}


void APlayerCharacterController::LoadLoseLevel()
{
	validate(MapsFolderPath.Len() > 0);

	if (validate(LoseGameLevelName.Len() > 0) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	World->ServerTravel(MapsFolderPath + LoseGameLevelName, true);
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
