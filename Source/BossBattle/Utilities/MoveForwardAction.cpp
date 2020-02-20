// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveForwardAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
MoveForwardAction::MoveForwardAction( ARLEnemyCharacter* CharacterToSet) : Action(CharacterToSet)
{
}

void MoveForwardAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->MoveForward(1.0f);
}
