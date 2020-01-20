// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "Characters/RLEnemyCharacter.h"

Action::Action(int IdToSet, ARLEnemyCharacter* CharacterToSet)
{
	Id = IdToSet;
	EnemyCharacter = CharacterToSet;
}

int Action::GetId()
{
	return Id;
}
