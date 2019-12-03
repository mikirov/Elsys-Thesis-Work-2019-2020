// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearFocus.h"


#include "AIController.h"

EBTNodeResult::Type UBTTask_ClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	AIController->ClearFocus(EAIFocusPriority::Gameplay);
	
	return EBTNodeResult::Succeeded;
}