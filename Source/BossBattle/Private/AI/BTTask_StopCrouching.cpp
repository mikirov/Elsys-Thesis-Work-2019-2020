// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StopCrouching.h"


#include "CustomMacros.h"
#include "BattleCharacter.h"


EBTNodeResult::Type UBTTask_StopCrouching::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	if (AICharacter->IsCrouching()) {
		AICharacter->EndCrouch();
	}

	return EBTNodeResult::Succeeded;
}
