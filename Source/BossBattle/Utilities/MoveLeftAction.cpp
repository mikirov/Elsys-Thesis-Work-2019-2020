// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
MoveLeftAction::MoveLeftAction(int Id, ARLEnemyCharacter* CharacterToSet) : Action(Id, CharacterToSet)
{

}

void MoveLeftAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->MoveRight(-1.0f);
}
