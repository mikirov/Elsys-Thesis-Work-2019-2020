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
#include "Characters/AIEnemyCharacter.h"
#include "Characters/PlayerCharacterController.h"
#include "Weapons/Projectile.h"
#include "Utilities/CustomMacros.h"




void ABossBattleGameMode::IncrementScore(const int Amount)
{
	CurrentScore += Amount;
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


