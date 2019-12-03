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
	//pure virtual
	virtual void Reset();


	
};
