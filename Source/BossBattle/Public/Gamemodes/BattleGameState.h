// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "BattleGameState.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ABattleGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	bool bPlaying = false;
};
