// Fill out your copyright notice in the Description page of Project Settings.


#include "RLEnemyController.h"

#include "AIController.h"
#include "Utilities/CustomMacros.h"

ARLEnemyController::ARLEnemyController()
{

	PrimaryActorTick.bCanEverTick = false;
}

void ARLEnemyController::BeginPlay()
{

	Super::BeginPlay();

	if (validate(RunBehaviorTree(BehaviorTreeTemplate)) == false) { return; }
}
