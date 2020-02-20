// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Utilities/Action.h"
/**
 * 
 */
class BOSSBATTLE_API InteractAction : public Action
{
public:
	InteractAction(ARLEnemyCharacter* CharacterToSet);
	void Execute() override;
};
