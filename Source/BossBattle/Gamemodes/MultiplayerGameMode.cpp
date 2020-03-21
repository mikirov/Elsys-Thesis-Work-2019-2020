// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameMode.h"

#include "Utilities/CustomMacros.h"
#include "Engine/World.h"
#include "Characters/PlayerCharacterController.h"
#include "Engine/DataTable.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"
#include "TimerManager.h"

#include "Gamemodes/BattleGameState.h"

void AMultiplayerGameMode::OnPlayerDeath(class APlayerCharacterController* PlayerController)
{

	if (validate(IsValid(PlayerController)) == false) return;
	//CurrentPlayers--;
	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::OnPlayerDeath(class APlayerCharacterController* PlayerController) CurrentPlayers: %d"), CurrentPlayers)

	Super::OnPlayerDeath(PlayerController);


	//if (CurrentPlayers == 0) {
	//	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::OnPlayerDeath:LoadLobby()"))

	//	LoadLobby();
	//}
}

void AMultiplayerGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	CurrentPlayers--;

	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::Logout(AController* Exiting) CurrentPlayers: %d"), CurrentPlayers)

	if (CurrentPlayers == 0) {
		LoadLobby();
	}
}

void AMultiplayerGameMode::LoadLobby()
{
	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::LoadLobby()"))

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	if (validate(LobbyMapName.Len() > 0) == false) return;

	World->ServerTravel(LobbyMapName);
}

void AMultiplayerGameMode::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::BeginPlay()"))

	Super::BeginPlay();
	//bUseSeamlessTravel = true;
}

void AMultiplayerGameMode::WinGame()
{
	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::WinGame()"))

	
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) {
		APlayerCharacterController* Controller = Cast<APlayerCharacterController>(*Iterator);
		if (validate(IsValid(Controller)) == false) return;

		UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::Controller->OnWinGame();"))

		Controller->OnWinGame();
	}

	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::AMultiplayerGameMode::LoadLobby"))

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle,this, &AMultiplayerGameMode::LoadLobby, 3.0f, false);
}



void AMultiplayerGameMode::UpdateHUDScore(int Score)
{
	UE_LOG(LogTemp, Warning, TEXT("AMultiplayerGameMode::UpdateHUDScore(int Score)"))

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
