// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractAction.h"
#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"

InteractAction::InteractAction(ARLEnemyCharacter* CharacterToSet) : Action(CharacterToSet)
{

}

void InteractAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->ServerInteractWithWeapon();
}
