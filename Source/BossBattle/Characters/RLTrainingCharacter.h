// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RLEnemyCharacter.h"
#include "RLTrainingCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLTrainingCharacter : public ARLEnemyCharacter
{
	GENERATED_BODY()
	
protected:
	AActor* GetClosestEnemy() override;
	
	void OnDeathAnimationEnd() override;

	void Destroyed() override;

	void Die() override;
};
