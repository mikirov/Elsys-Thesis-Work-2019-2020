// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayingGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine/TriggerBox.h"
#include "TimerManager.h"

#include "Characters/BattleCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/AIEnemyCharacter.h"
#include "Characters/PlayerCharacterController.h"
#include "Weapons/Projectile.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"
#include "Utilities/Spawner.h"
#include "Utilities/SpawnerTable.h"
#include "Utilities/CustomMacros.h"


void APlayingGameMode::PostLogin(APlayerController* PlayerController) {

	Super::PostLogin(PlayerController);


	if (bPlaying == true) return;

	//do not accept connections after the maximum player number is reached
	if (PlayerControllers.Num() == MaxPlayersCount) return;

	APlayerCharacterController* PlayerCharacterController = Cast<APlayerCharacterController>(PlayerController);
	if (validate(IsValid(PlayerCharacterController))) {
		PlayerControllers.Add(PlayerCharacterController);
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerControllers.Num(): %d"), PlayerControllers.Num());
	if (PlayerControllers.Num() == MaxPlayersCount && bPlaying == false) {
		SpawnEnemyWave();
		bPlaying = true;
	}
}

void APlayingGameMode::BeginPlay()
{
	Super::BeginPlay();

	WaveCount = SpawnerLookupTable->GetRowNames().Num();
}

void APlayingGameMode::SpawnEnemyWave()
{
	if (CurrentWaveIndex == WaveCount) {
		WinGame();
		return;
	}

	if (validate(IsValid(SpawnerLookupTable)) == false) { return; }

	FString ContextString(TEXT("GENERAL"));
	FName WaveName = FName(*FString::FromInt(CurrentWaveIndex));
	FSpawnerTable* SpawnerLookupRow = SpawnerLookupTable->FindRow<FSpawnerTable>(WaveName, ContextString);
	if (validate(SpawnerLookupRow != nullptr) == false) { return; }
	TArray<FSpawnerInfoArray> WaveInfo = SpawnerLookupRow->SpawnerEnemyPlacement;

	TArray<AActor*> Spawners;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawner::StaticClass(), Spawners);

	if (validate(WaveInfo.Num() >= Spawners.Num()) == false) { return; }

	for (int i = 0; i < Spawners.Num(); i++) {
		ASpawner* Spawner = Cast<ASpawner>(Spawners[i]);
		if (validate(IsValid(Spawner)) == false) { continue; }
		FSpawnerInfoArray SpawnerEnemyPlacements = WaveInfo[i];

		if (validate(SpawnerEnemyPlacements.SpawnerInfoArray.Num() != 0) == false) continue;
		for (FSpawnerInfo SpawnerInfo : SpawnerEnemyPlacements.SpawnerInfoArray) {
			if (validate(IsValid(SpawnerInfo.EnemyAsset)) == false) { continue; }
			Spawner->SpawnEnemy(SpawnerInfo.EnemyAsset, SpawnerInfo.EnemyCount);
		}
	}
}

void APlayingGameMode::IncrementScore(const int Amount)
{
	Super::IncrementScore(Amount);
	UpdateHUDScore(CurrentScore);
}

void APlayingGameMode::UpdateHUDScore(int Score) {
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




void APlayingGameMode::WinGame()
{
	for (int i = 0; i < PlayerControllers.Num(); i++) {
		PlayerControllers[i]->OnWinGame();
	}
	PlayerControllers.Empty();
	bPlaying = false;
}



void APlayingGameMode::DecrementEnemyCounter()
{
	Super::DecrementEnemyCounter();

	if (AreAllEnemiesDead()) {
		CurrentWaveIndex++;
		//We win the game after all the enemy waves and the boss wave
		if (CurrentWaveIndex == WaveCount) {
			UE_LOG(LogTemp, Display, TEXT("You won the game"));
			WinGame();
		}
		else {
			//TODO: add delay between waves
			SpawnEnemyWave();
		}
	}
}


void APlayingGameMode::OnPlayerDeath(APlayerCharacterController* PlayerController)
{
	if (validate(IsValid(PlayerController)) == false) return;
	PlayerControllers.Remove(PlayerController);
	if (PlayerControllers.Num() == 0) {
		bPlaying = false;
	}

	PlayerController->OnLoseGame();
	

}

TArray<class APlayerCharacterController*> APlayingGameMode::GetPlayerControllers()
{
	return PlayerControllers;
}
