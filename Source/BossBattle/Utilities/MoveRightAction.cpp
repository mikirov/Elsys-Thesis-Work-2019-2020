// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRightAction.h"


#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
MoveRightAction::MoveRightAction(ARLEnemyCharacter* CharacterToSet) : Action(CharacterToSet)
{

}

void MoveRightAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->MoveRight(1.0f);
}
