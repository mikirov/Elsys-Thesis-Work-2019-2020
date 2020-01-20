// Fill out your copyright notice in the Description page of Project Settings.


#include "ReloadAction.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"
ReloadAction::ReloadAction(int Id, ARLEnemyCharacter* CharacterToSet) : Action(Id, CharacterToSet)
{

}

void ReloadAction::Execute()
{
	if (IsValid(EnemyCharacter) == false) return;
	EnemyCharacter->ServerStartReloading();
}
