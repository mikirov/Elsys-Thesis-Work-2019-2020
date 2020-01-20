// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utilities/Action.h"

/**
 * 
 */
class BOSSBATTLE_API MoveForwardAction : public Action
{
public:
	MoveForwardAction(int Id, ARLEnemyCharacter* CharacterToSet);
	void Execute() override;
};