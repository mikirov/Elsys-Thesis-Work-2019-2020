// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_StartFiring.h"

#include "Utilities/CustomMacros.h"
#include "Characters/BattleCharacter.h"


EBTNodeResult::Type UBTTask_StartFiring::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	AICharacter->ServerStartFiringRequest();

	return EBTNodeResult::Succeeded;
}
