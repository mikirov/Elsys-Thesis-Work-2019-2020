// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */


UCLASS()
class BOSSBATTLE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	AEnemyAIController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BehaviorTreeTemplate = nullptr;

	//UPROPERTY(EditDefaultsOnly)
	//class UAIPerceptionComponent* PerceptionComponent = nullptr;


};