// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameMode.h"


#include "Characters/PlayerCharacterController.h"
#include "Utilities/CustomMacros.h"

#include "Utilities/Spawner.h"
#include "Utilities/SpawnerTable.h"

#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"

#include "Gamemodes/BattleGameState.h"

void AMultiplayerGameMode::OnPlayerDeath(class APlayerCharacterController* PlayerController)
{
	if (validate(IsValid(PlayerController)) == false) return;
	PlayerControllers.Remove(PlayerController);
	if (PlayerControllers.Num() == 0) {
		bPlaying = false;
	}

	Super::OnPlayerDeath(PlayerController);
}

TArray<class APlayerCharacterController*> AMultiplayerGameMode::GetPlayerControllers()
{
	return PlayerControllers;
}

void AMultiplayerGameMode::BeginPlay()
{

	//Super::BeginPlay();

	WaveCount = SpawnerLookupTable->GetRowNames().Num();
}

void AMultiplayerGameMode::WinGame()
{
	for (int i = 0; i < PlayerControllers.Num(); i++) {
		PlayerControllers[i]->OnWinGame();
	}
	PlayerControllers.Empty();
	bPlaying = false;

}

void AMultiplayerGameMode::PreLogin(const FString & Options, const FString & Address, const FUniqueNetIdRepl & UniqueId, FString & ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);


	if (bPlaying == true || CurrentPlayers >= MaxPlayersCount) {
		ErrorMessage = "Cannot join";
	}


}


void AMultiplayerGameMode::PostLogin(class APlayerController* PlayerController)
{
	Super::PostLogin(PlayerController);

	CurrentPlayers++;

	APlayerCharacterController* PlayerCharacterController = Cast<APlayerCharacterController>(PlayerController);
	if (validate(IsValid(PlayerCharacterController))) {
		PlayerControllers.Add(PlayerCharacterController);
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerControllers.Num(): %d"), PlayerControllers.Num());
	if (PlayerControllers.Num() >= MaxPlayersCount && bPlaying == false) {
		SpawnEnemyWave();
		bPlaying = true;
	}
}


void AMultiplayerGameMode::Logout(AController* Exiting)
{
	CurrentPlayers--;
}



void AMultiplayerGameMode::UpdateHUDScore(int Score)
{
	for (APlayerCharacterController* PlayerController : PlayerControllers) {
		if (validate(IsValid(PlayerController)) == false) { continue; }

		ABattleHUD* HUD = Cast<ABattleHUD>(PlayerController->GetHUD());
		if (validate(IsValid(HUD)) == false) { continue; }

		UPlayerStatsWidget* PlayerStats = HUD->GetPlayerStatsWidget();
		if (validate(IsValid(PlayerStats))) {
			PlayerStats->SetScore(Score);
		}
	}
}
