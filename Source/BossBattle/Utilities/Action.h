// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Characters/RLEnemyCharacter.h"
/**
 * 
 */
class BOSSBATTLE_API Action
{
public:
	
	Action(class ARLEnemyCharacter* CharacterToSet);

	//execute method overriten by every action
	virtual void Execute();

protected:
	
	//character that executes the action
	class ARLEnemyCharacter* EnemyCharacter = nullptr;

};
