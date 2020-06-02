// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_BaseBlackboardTask.generated.h"


/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTTask_BaseBlackboardTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;

	class UBlackboardComponent* BlackboardComponent = nullptr;

	class APawn* AICharacter = nullptr;

	class AAIController* AIController = nullptr;

};
