// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_BaseBlackboardTask.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Utilities/CustomMacros.h"


EBTNodeResult::Type UBTTask_BaseBlackboardTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (validate(IsValid(BlackboardComponent)) == false) { return EBTNodeResult::Aborted; }
	AIController = OwnerComp.GetAIOwner();
	if (validate(IsValid(AIController)) == false) { return EBTNodeResult::Aborted; }

	AICharacter = AIController->GetPawn();
	if (validate(IsValid(AICharacter)) == false) { return EBTNodeResult::Aborted; }

	return EBTNodeResult::Succeeded;
}

void UBTTask_BaseBlackboardTask::OnGameplayTaskDeactivated(UGameplayTask& Task)
{

}

void UBTTask_BaseBlackboardTask::OnGameplayTaskActivated(UGameplayTask& Task)
{

}
