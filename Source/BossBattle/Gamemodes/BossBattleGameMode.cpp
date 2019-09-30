// Fill out your copyright notice in the Description page of Project Settings.


#include "BossBattleGameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine/TriggerBox.h"
#include "Characters/BattleCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacterController.h"
#include "Weapons/Projectile.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"
#include "Utilities/Spawner.h"
#include "Utilities/SpawnerTable.h"
#include "Utilities/CustomMacros.h"


void ABossBattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	PlayerTemplate = DefaultPawnClass;
	validate(IsValid(PlayerTemplate));

	TArray<AActor*>	RespawnBoxes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerBox::StaticClass(), RespawnBoxes);
	if (validate(RespawnBoxes.Num() != 0) == false) return;
	RespawnBox = Cast<ATriggerBox>(RespawnBoxes[0]);

	FindPlayerControllers();

	validate(MapsFolderPath.Len() > 0);
	
	if (validate(IsValid(SpawnerLookupTable)) == false) return;
	WaveCount = SpawnerLookupTable->GetRowNames().Num();
	SpawnEnemyWave();

}

void ABossBattleGameMode::FindPlayerControllers() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	PlayerControllers.Reset();
	TArray<AActor*> PlayerControllerActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacterController::StaticClass(), PlayerControllerActors);

	for (AActor* PlayerControllerActor : PlayerControllerActors) {
		APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(PlayerControllerActor);
		if (validate(IsValid(PlayerController))) {
			PlayerControllers.Add(PlayerController);
		}
	}
}

void ABossBattleGameMode::SpawnEnemyWave()
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

void ABossBattleGameMode::IncrementScore(const int Amount)
{
	CurrentScore += Amount;
	UpdateHUDScore(CurrentScore);
}

void ABossBattleGameMode::UpdateHUDScore(int Score) {
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


void ABossBattleGameMode::RespawnPlayer(APlayerController* PlayerController)
{
	if (validate(HasAuthority()) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	if (validate(IsValid(PlayerController)) == false) { return; }

	APawn* PlayerCharacter = PlayerController->GetPawn();
	if (IsValid(PlayerCharacter)) {
		PlayerCharacter->Destroy();
	}

	//Spawn The player and possess him by the player controller
	if (validate(IsValid(PlayerTemplate)) == false) { return; }
	if (validate(IsValid(RespawnBox)) == false) return;

	FVector ActorLocation;
	FVector BoxExtent;
	RespawnBox->GetActorBounds(false, ActorLocation, BoxExtent);

	FTransform PlayerRespawnLocation = FTransform(
		UKismetMathLibrary::RandomPointInBoundingBox(
			ActorLocation,
			BoxExtent
		)
	);


	FActorSpawnParameters ActorSpawnParameters;
	ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ABattleCharacter* PlayerActor = World->SpawnActor<ABattleCharacter>(PlayerTemplate, PlayerRespawnLocation, ActorSpawnParameters);
	PlayerController->Possess(PlayerActor);
}



void ABossBattleGameMode::WinGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Win Game!"));
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	for (auto it = World->GetPlayerControllerIterator(); it; it++) {
		APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(it->Get());
		if (validate(IsValid(PlayerController)) == false) { return; }
		PlayerController->OnWinGame();
	}

	FTimerHandle RespawnTimerHandle; // not used anywhere
	GetWorldTimerManager().SetTimer(
		RespawnTimerHandle,
		this,
		&ABossBattleGameMode::LoadWinLevel,
		3
	);
}

void ABossBattleGameMode::LoseGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Lose Game!"));
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	for (auto it = World->GetPlayerControllerIterator(); it; it++) {
		APlayerCharacterController* PlayerController = Cast<APlayerCharacterController>(it->Get());
		if (validate(IsValid(PlayerController)) == false) { return; }
		PlayerController->OnLoseGame();
	}

	FTimerHandle RespawnTimerHandle; // not used anywhere else
	GetWorldTimerManager().SetTimer(
		RespawnTimerHandle,
		this,
		&ABossBattleGameMode::RestartLevel,
		3
	);
}

bool ABossBattleGameMode::AreAllEnemiesDead()
{
	return CurrentEnemies <= 0;
}

void ABossBattleGameMode::IncrementEnemyCounter(int EnemyCount)
{
	CurrentEnemies += EnemyCount;
}

void ABossBattleGameMode::DecrementEnemyCounter()
{
	CurrentEnemies -= 1;
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

void ABossBattleGameMode::RestartLevel() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	World->ServerTravel(MapsFolderPath + World->GetName(), true);
}


void ABossBattleGameMode::LoadWinLevel() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	if (validate(WinGameLevelName.Len() > 0) == false) { return; }

	World->ServerTravel(MapsFolderPath + WinGameLevelName, true);
}