// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "MoveRightAction.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class REINFORCEMENTLEARNING_API UMoveRightAction : public UAction
{

	GENERATED_BODY()
public:

	UMoveRightAction();

	bool Execute_Implementation() override;
};
