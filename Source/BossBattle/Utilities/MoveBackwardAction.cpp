// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBackwardAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
MoveBackwardAction::MoveBackwardAction(int Id, ARLEnemyCharacter* CharacterToSet) : Action(Id, CharacterToSet)
{
}

void MoveBackwardAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->MoveForward(-1.0f);
}
