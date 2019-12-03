// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Perception/AIPerceptionComponent.h"

#include "../../Utilities/CustomMacros.h"


AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = false;

	//PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(FName("PerceptionComponent"));
	//if (validate(IsValid(PerceptionComponent)) == false) return;

}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

	if (validate(RunBehaviorTree(BehaviorTreeTemplate)) == false) { return; }
}

