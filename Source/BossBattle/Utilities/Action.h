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
	
	Action(int Id, class ARLEnemyCharacter* CharacterToSet);

	int GetId();

	//pure virtual
	virtual void Execute() = 0;

protected:
	int Id;
	
	class ARLEnemyCharacter* EnemyCharacter = nullptr;

};
