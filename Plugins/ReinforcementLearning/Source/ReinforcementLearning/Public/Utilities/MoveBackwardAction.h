// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "MoveBackwardAction.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class REINFORCEMENTLEARNING_API UMoveBackwardAction : public UAction
{
	GENERATED_BODY()
public:

	UMoveBackwardAction();

	bool Execute_Implementation() override;
};
