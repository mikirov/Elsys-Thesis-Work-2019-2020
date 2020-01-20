// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RLEnemyCharacter.h"
#include "RLGameCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLGameCharacter : public ARLEnemyCharacter
{
	GENERATED_BODY()
	
protected:
	ACharacter* GetClosestEnemy() override;

	void Die() override;
};
