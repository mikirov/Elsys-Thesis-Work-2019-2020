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

	//The behavior tree template to be loaded at BeginPlay by the controller
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BehaviorTreeTemplate = nullptr;


};