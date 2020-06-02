// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RLEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class ARLEnemyController : public AAIController
{
	GENERATED_BODY()
public:
	ARLEnemyController();
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//The behavior tree template to be loaded at BeginPlay by the controller
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BehaviorTreeTemplate = nullptr;

};
