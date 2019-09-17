// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "Utilities/CustomMacros.h"


AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

	if (validate(RunBehaviorTree(BehaviorTreeTemplate)) == false) { return; }
}

