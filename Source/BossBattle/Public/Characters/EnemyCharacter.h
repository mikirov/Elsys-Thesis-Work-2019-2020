// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BattleCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AEnemyCharacter : public ABattleCharacter
{
	GENERATED_BODY()
	
public:

	void BeginPlay();

	void Die() override;

protected:


	void OnTakingDamage(float Amount) override;
	
	// Added score when enemy dies.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float Score = 500.0f;

};
