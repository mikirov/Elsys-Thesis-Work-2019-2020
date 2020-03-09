// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/EnemyCharacter.h"

#include "RLEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLEnemyCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
	
public:

	void FocusOnEnemy();

	//action binding function. Moves the character forwards or backwards
	void MoveForward(float Value);

	//action binding function. Moves the character left or right
	void MoveRight(float Value);

	void BeginPlay() override;

protected:

	void OnDeathAnimationEnd() override;

	void Destroyed() override;

	UPROPERTY(EditDefaultsOnly)
	class ASpawner* Spawner = nullptr;

	virtual AActor* GetClosestEnemy();

};
