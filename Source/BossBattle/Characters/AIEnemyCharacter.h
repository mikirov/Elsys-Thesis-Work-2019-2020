// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/EnemyCharacter.h"
#include "AIEnemyCharacter.generated.h"


UCLASS()
class BOSSBATTLE_API AAIEnemyCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIEnemyCharacter();

	void SetTarget(class AActor* Target);
	
	void Die() override;

protected:

	// target player used for checking collision actor
	class AActor* Target = nullptr;

};
