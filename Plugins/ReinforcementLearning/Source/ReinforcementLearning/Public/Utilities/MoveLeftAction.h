// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "MoveLeftAction.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class REINFORCEMENTLEARNING_API UMoveLeftAction : public UAction
{
	GENERATED_BODY()

public:
	UMoveLeftAction();

	bool Execute_Implementation() override;
};
