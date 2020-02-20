// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
ReloadAction::ReloadAction(ARLEnemyCharacter* CharacterToSet) : Action(CharacterToSet)
{

}

void ReloadAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->ServerStartReloading();
}
