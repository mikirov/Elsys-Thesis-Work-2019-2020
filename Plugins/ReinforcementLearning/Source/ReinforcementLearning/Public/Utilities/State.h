// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/ActorComponent.h"
#include "State.generated.h"
/**
 * 
 */
UCLASS(BLueprintable)
class REINFORCEMENTLEARNING_API UState : public UActorComponent
{

	GENERATED_BODY()
public:
	

	UState();

	void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	bool IsSatisfied();

	virtual bool IsSatisfied_Implementation();

	float GetReward();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float PotentialAmount = 0.0f;

	class APawn* Pawn = nullptr;
};
