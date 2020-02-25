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
		LoadLobby();
	}
	Super::OnPlayerDeath(PlayerController);
}

void AMultiplayerGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	CurrentPlayers--;

	if (CurrentPlayers == 0) {
		LoadLobby();
	}
}

void AMultiplayerGameMode::LoadLobby()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	if (validate(LobbyMapName.Len() > 0) == false) return;

	World->ServerTravel(LobbyMapName);
}

void AMultiplayerGameMode::BeginPlay()
{
	Super::BeginPlay();

}

void AMultiplayerGameMode::WinGame()
{
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) {
		APlayerCharacterController* Controller = Cast<APlayerCharacterController>(*Iterator);
		if (validate(IsValid(Controller)) == false) return;

		Controller->OnWinGame();
	}
	LoadLobby();

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
