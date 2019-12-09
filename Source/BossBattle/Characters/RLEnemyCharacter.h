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

	UFUNCTION(BlueprintCallable)
	void UpdateStateAction(bool bDidKill, bool bDidDie);
	
	void Reset() override;

	void ClearFocus();

	void ShootAICharacter();

	void FocusOnAICharacter();

	void MoveNearAICharacter();

	void ReportNoise();

protected:
	
	void BeginPlay();
	
	// Does the character have the flag?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bHasFlag = false;

	// Does the character hear noise?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bHearsNoise = false;

	// Does the character see an enemy?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bSeeEnemy = false;
	
	// is the RL character hitting the AI character?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bHittingAICharacter = false;

	// Is the character bumping into anything?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bBumping = false;

	// Is the character taking damage?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bTakingDamage = false;

	// Is the character moving?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bMoving = false;

	// Is on critical health ?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	bool bCriticalHealth = false;

	// Distance to the enemy
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RL Character")
	float bEnemyDistance = 0.0;

	// Is the character dead?
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "RL Character")
	bool bDead = false;

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

	FString CurrentState;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "RL Character")
	FString CurrentAction;

	FString PreviousStateAction;

	TArray<FString> StateStringArray;

	TMap<FString, float> MaxStateValues;

	TArray<FString> StateActionStrings;

	TArray<float> ActionValues;

	TMap<FString, float> StateTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Epsilon = 0.1f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	bool bRandomAction = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float NextStateActionValue = 0.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float DiscountFactor = 0.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "RL Character")
	float LearningRate = 0.9f;



};
