// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_StartFiring.h"

#include "CustomMacros.h"
#include "BattleCharacter.h"


EBTNodeResult::Type UBTTask_StartFiring::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	if (AICharacter->IsFiring() == false) {
		AICharacter->StartFiring();
	}

	return EBTNodeResult::Succeeded;
}
