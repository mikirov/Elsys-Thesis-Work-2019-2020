// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_SetNull.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTask_SetNull::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);

	return EBTNodeResult::Succeeded;

}
