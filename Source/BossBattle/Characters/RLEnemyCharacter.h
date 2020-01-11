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

	void Reset() override;

	void ShootAICharacter();

	void FocusOnAICharacter();

	void MoveNearAICharacter();


protected:
	
	void BeginPlay();
	
	void Tick(float DeltaTime);

	// is the RL character hitting the AI character?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bDealingDamage = false;

	// Is the character taking damage?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bTakingDamage = false;

	// Is on critical health ?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bCriticalHealth = false;

	// Is the character dead?
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "RL Character")
	bool bDead = false;

	int CurrentAction;

	UFUNCTION()
	void ClearTakingDamage();

	UFUNCTION()
	void OnHealthChanged(int CurrnetHealth);

	void Die() override;

	FTransform InitialTransform;

	float CurrentReward = 0.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float KillReward = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DeathReward = -1.0f;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DealingDamageReward = 0.1f;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float TakingDamageReward = -0.1f;

	//random action chance
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Epsilon = 0.1f;

	//whether or not the character should take a random action
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	bool bRandomAction = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float NextStateActionValue = 0.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DiscountFactor = 0.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float LearningRate = 0.9f;

	void MoveForward(float Value);

	void MoveRight(float Value);

};
