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
#include "UObject/ConstructorHelpers.h"

#include "Characters/BattleCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacterController.h"
#include "Weapons/Projectile.h"
#include "UI/BattleHUD.h"
#include "UI/PlayerStatsWidget.h"
#include "Utilities/Spawner.h"
#include "Utilities/CustomMacros.h"

ABossBattleGameMode::ABossBattleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

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
}

void ABossBattleGameMode::LoseGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Lose Game!"));
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