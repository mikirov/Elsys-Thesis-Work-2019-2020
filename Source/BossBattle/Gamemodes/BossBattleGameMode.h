// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BossBattleGameMode.generated.h"

/**
 * 
 */

UCLASS()
class BOSSBATTLE_API ABossBattleGameMode : public AGameModeBase
{

	GENERATED_BODY()
public:

	// Increments the score by a given amount
	void IncrementScore(const int Amount);

	virtual void IncrementEnemyCounter(int EnemyCount);

	virtual void DecrementEnemyCounter();
	


protected:

	void BeginPlay() override;

	bool AreAllEnemiesDead();

	int CurrentScore = 0;

	int CurrentEnemies = 0;



};
