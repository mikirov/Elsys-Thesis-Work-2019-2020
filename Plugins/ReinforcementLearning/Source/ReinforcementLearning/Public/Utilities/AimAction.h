// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "AimAction.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class REINFORCEMENTLEARNING_API UAimAction : public UAction
{
	GENERATED_BODY()

public:
	UAimAction();

	bool Execute_Implementation() override;
};
