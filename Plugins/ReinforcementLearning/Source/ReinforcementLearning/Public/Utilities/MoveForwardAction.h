// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "MoveForwardAction.generated.h"

/**
 * 
 */

UCLASS(meta = (BlueprintSpawnableComponent))
class REINFORCEMENTLEARNING_API UMoveForwardAction : public UAction
{
	GENERATED_BODY()

public:

	UMoveForwardAction();

	bool Execute_Implementation() override;
};
