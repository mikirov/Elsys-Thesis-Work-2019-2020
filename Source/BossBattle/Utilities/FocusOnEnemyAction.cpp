// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusOnEnemyAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"

FocusOnEnemyAction::FocusOnEnemyAction(ARLEnemyCharacter* CharacterToSet) : Action(CharacterToSet)
{

}

void FocusOnEnemyAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->FocusOnEnemy();
}
