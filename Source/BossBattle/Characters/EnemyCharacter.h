// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BattleCharacter.h"
#include "EnemyCharacter.generated.h"


UCLASS()
class BOSSBATTLE_API AEnemyCharacter : public ABattleCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	void SetTarget(class AActor* Target);

protected:

	void Die() override;

	// Added score when enemy dies.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float Score = 500.0f;

	// target player used for checking collision actor
	class AActor* Target = nullptr;

};
