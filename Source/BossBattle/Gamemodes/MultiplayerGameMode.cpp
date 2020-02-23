// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameMode.h"

#include "Utilities/CustomMacros.h"
#include "Engine/World.h"
#include "Characters/PlayerCharacterController.h"
#include "Engine/DataTable.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"

#include "Gamemodes/BattleGameState.h"

void AMultiplayerGameMode::OnPlayerDeath(class APlayerCharacterController* PlayerController)
{
	if (validate(IsValid(PlayerController)) == false) return;
	CurrentPlayers--;
	if (CurrentPlayers == 0) {
		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) return;

		World->ServerTravel(LobbyMapName);
	}
	Super::OnPlayerDeath(PlayerController);
}

void AMultiplayerGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	CurrentPlayers--;

	if (CurrentPlayers == 0) {
		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) return;

		World->ServerTravel(LobbyMapName);

	}
}

void AMultiplayerGameMode::BeginPlay()
{
	WaveCount = SpawnerLookupTable->GetRowNames().Num();

}

void AMultiplayerGameMode::WinGame()
{
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) {
		APlayerCharacterController* Controller = Cast<APlayerCharacterController>(*Iterator);
		if (validate(IsValid(Controller)) == false) return;

		Controller->OnWinGame();
	}
	UWorld* World = GetWorld();
	if (validate(World) == false) return;

	World->ServerTravel(LobbyMapName);

}



void AMultiplayerGameMode::UpdateHUDScore(int Score)
{

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) {
		APlayerCharacterController* Controller = Cast<APlayerCharacterController>(*Iterator);
		if (validate(IsValid(Controller)) == false) return;

		ABattleHUD* HUD = Cast<ABattleHUD>(Controller->GetHUD());
		if (validate(IsValid(HUD)) == false) { continue; }

		UPlayerStatsWidget* PlayerStats = HUD->GetPlayerStatsWidget();
		if (validate(IsValid(PlayerStats))) {
			PlayerStats->SetScore(Score);
		}


	}
}
