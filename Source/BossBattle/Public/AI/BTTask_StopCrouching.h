// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseNode.h"
#include "BTTask_StopCrouching.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTTask_StopCrouching : public UBTTask_BaseNode
{
	GENERATED_BODY()

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
