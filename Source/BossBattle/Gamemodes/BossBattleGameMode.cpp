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


void ABossBattleGameMode::PostLogin(APlayerController* PlayerController) {
	
	Super::PostLogin(PlayerController);

	//do not accept connections after the maximum player number is reached
	if (PlayerControllers.Num() == MaxPlayersCount) return;

	APlayerCharacterController* PlayerCharacterController = Cast<APlayerCharacterController>(PlayerController);
	if (validate(IsValid(PlayerCharacterController))) {
		PlayerControllers.Add(PlayerCharacterController);
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerControllers.Num(): %d"), PlayerControllers.Num())
	if (PlayerControllers.Num() == MaxPlayersCount) {
		SpawnEnemyWave();
	}
}

void ABossBattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	PlayerTemplate = DefaultPawnClass;
	validate(IsValid(PlayerTemplate));

	TArray<AActor*>    RespawnBoxes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerBox::StaticClass(), RespawnBoxes);
	if (validate(RespawnBoxes.Num() != 0) == false) return;
	RespawnBox = Cast<ATriggerBox>(RespawnBoxes[0]);

	WaveCount = SpawnerLookupTable->GetRowNames().Num();
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


void ABossBattleGameMode::RespawnPlayer(APlayerCharacterController* PlayerController)
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
	for (int i = 0; i < PlayerControllers.Num(); i++) {
		PlayerControllers[i]->OnWinGame();
	}
	PlayerControllers.Empty();
}

void ABossBattleGameMode::LoseGame()
{
	for (int i = 0; i < PlayerControllers.Num(); i++) {
		PlayerControllers[i]->OnLoseGame();
	}
	PlayerControllers.Empty();
	CurrentWaveIndex = 0;
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


void ABossBattleGameMode::OnPlayerDeath(APlayerCharacterController* PlayerController)
{

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	int DeadPlayers = 0;
	int AllPlayers = 0;
	for (auto it = World->GetPlayerControllerIterator(); it; it++) {
		APlayerCharacterController* CurrentPlayerController = Cast<APlayerCharacterController>(it->Get());
		if (validate(IsValid(CurrentPlayerController)) == false) { return; }
		if (CurrentPlayerController->HasEverDied()) {
			DeadPlayers++;
		}
		AllPlayers++;
	}
	if (DeadPlayers == AllPlayers) {
		LoseGame();
	}

	FTimerHandle DeathTimerHandle;
	FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &ABossBattleGameMode::RespawnPlayer, PlayerController);

	GetWorldTimerManager().SetTimer(DeathTimerHandle, RespawnDelegate, RespawnCooldown, false, -1.f);
}
