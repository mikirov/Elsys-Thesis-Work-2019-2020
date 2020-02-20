// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "Characters/RLEnemyCharacter.h"

Action::Action( ARLEnemyCharacter* CharacterToSet)
{
	EnemyCharacter = CharacterToSet;
}


void Action::Execute()
{
	UE_LOG(LogTemp, Warning, TEXT("Action::Execute()"))
}
