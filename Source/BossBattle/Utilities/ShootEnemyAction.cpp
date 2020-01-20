// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootEnemyAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
ShootEnemyAction::ShootEnemyAction(int Id, ARLEnemyCharacter* CharacterToSet) : Action(Id, CharacterToSet)
{
}

void ShootEnemyAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->ServerStartFiring();
}
