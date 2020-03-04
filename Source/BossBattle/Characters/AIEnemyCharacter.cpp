// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemyCharacter.h"
#include "Engine/World.h"

#include "Gamemodes/BossBattleGameMode.h"
#include "Gamemodes/TrainingGameMode.h"
#include "Utilities/CustomMacros.h"


// Sets default values
AAIEnemyCharacter::AAIEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}


void AAIEnemyCharacter::SetTarget(AActor* TargetToSet) {
	if (validate(IsValid(TargetToSet)) == false) { return; }

	Target = TargetToSet;
}

void AAIEnemyCharacter::Die()
{
	UE_LOG(LogTemp, Warning, TEXT("AAIEnemyCharacter::Die()"))

	Super::Die();

	if (HasAuthority()) {
		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }


		ABossBattleGameMode* GameMode = Cast<ABossBattleGameMode>(World->GetAuthGameMode());
		if (validate(IsValid(GameMode))) {
			GameMode->DecrementEnemyCounter();
			return;
		}
	}

}

void AAIEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

