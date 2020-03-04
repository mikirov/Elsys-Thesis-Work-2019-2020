// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BattleCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AEnemyCharacter : public ABattleCharacter
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
	void Reset();

	void BeginPlay();
	
	bool IsTakingDamage();

	bool IsDead();

	bool IsOnCriticalHealth();

	void Die() override;

protected:

	// Is the character dead?
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Enemy Character")
	bool bDead = false;

	// Is the character taking damage?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Character")
	bool bTakingDamage = false;

	// Is the character on critical health ?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Character")
	bool bCriticalHealth = false;

	UFUNCTION()
	void OnTakingDamage(float Amount);
	
	UFUNCTION()
	void ClearTakingDamage();

	// Added score when enemy dies.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float Score = 500.0f;

};
