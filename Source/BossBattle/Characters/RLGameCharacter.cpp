// Fill out your copyright notice in the Description page of Project Settings.


#include "RLGameCharacter.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Characters/AIEnemyCharacter.h"
#include <limits>


#include "Characters/PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Characters/PlayerCharacterController.h"
#include "Gamemodes/PlayingGameMode.h"
#include "Utilities/CustomMacros.h"

ACharacter* ARLGameCharacter::GetClosestEnemy()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return nullptr; }

	APlayerCharacter* ChosenPlayerCharacter = nullptr;
	float CurrentDistance = std::numeric_limits<float>::max();

	APlayingGameMode* GameMode = Cast<APlayingGameMode>(World->GetAuthGameMode());
	if (validate(IsValid(GameMode)) == false) return nullptr;

	TArray<APlayerCharacterController*> Controllers = GameMode->GetPlayerControllers();
	for (APlayerCharacterController* PlayerController : Controllers) {
		if (validate(IsValid(PlayerController)) == false) { continue; }

		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerController->GetPawn());
		if (IsValid(PlayerCharacter) == false) { continue; }

		float DistanceToPlayer = FVector::Dist(PlayerCharacter->GetActorLocation(), GetActorLocation());
		if (DistanceToPlayer < CurrentDistance) {
			ChosenPlayerCharacter = PlayerCharacter;
			CurrentDistance = DistanceToPlayer;
		}
	}


	return ChosenPlayerCharacter;

}

void ARLGameCharacter::Die()
{
	Super::Die();

}
