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
#include "Characters/PlayerCharacterController.h"
#include "Weapons/Projectile.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"
#include "Utilities/Spawner.h"
#include "Utilities/SpawnerTable.h"
#include "Utilities/CustomMacros.h"

void APlayingGameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::BeginPlay()"))
	//bUseSeamlessTravel = true;
	WaveCount = SpawnerLookupTable->GetRowNames().Num();

	SpawnEnemyWave();
}

void APlayingGameMode::SpawnEnemyWave()
{

	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::SpawnEnemyWave"))
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

	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::IncrementScore(const int Amount)"))
	Super::IncrementScore(Amount);
	UpdateHUDScore(CurrentScore);
}

void APlayingGameMode::UpdateHUDScore(int Score) {


	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::UpdateHUDScore(int Score)"))
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(World, 0));
	if (validate(IsValid(PlayerController)) == false) return;

	ABattleHUD* HUD = Cast<ABattleHUD>(PlayerController->GetHUD());
	if (validate(IsValid(HUD)) == false) { return; }

	UPlayerStatsWidget* PlayerStats = HUD->GetPlayerStatsWidget();
	if (validate(IsValid(PlayerStats))) {
		PlayerStats->SetScore(Score);
	}
	
}




void APlayingGameMode::WinGame()
{

	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::WinGame()"))
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	APlayerCharacterController* PlayerController =  Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(World, 0));
	if (validate(IsValid(PlayerController)) == false) return;
	PlayerController->OnWinGame();
}



void APlayingGameMode::DecrementEnemyCounter()
{

	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::DecrementEnemyCounter()"))
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


TArray<class APlayerCharacterController*> APlayingGameMode::GetPlayerControllers()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return TArray<APlayerCharacterController*>();
	APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(World, 0));
	if (validate(IsValid(PlayerController)) == false) return TArray<APlayerCharacterController*>();

	TArray<APlayerCharacterController*> PlayerControllers;
	PlayerControllers.Add(PlayerController);
	return PlayerControllers;
}

void APlayingGameMode::OnPlayerDeath(APlayerCharacterController* PlayerController)
{
	UE_LOG(LogTemp, Warning, TEXT("APlayingGameMode::OnPlayerDeath(APlayerCharacterController* PlayerController)"))
	PlayerController->OnLoseGame();
}

