// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootEnemyAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
ShootEnemyAction::ShootEnemyAction(ARLEnemyCharacter* CharacterToSet) : Action(CharacterToSet)
{
}

void ShootEnemyAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->ServerStartFiring();
}
