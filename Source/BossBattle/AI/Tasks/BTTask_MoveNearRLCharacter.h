// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Tasks/BTTask_BaseBlackboardTask.h"
#include "BTTask_MoveNearRLCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTTask_MoveNearRLCharacter : public UBTTask_BaseBlackboardTask
{
	GENERATED_BODY()
	


	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
