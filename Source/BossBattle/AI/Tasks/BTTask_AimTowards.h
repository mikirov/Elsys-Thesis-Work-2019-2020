// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTTask_BaseBlackboardTask.h"
#include "BTTask_AimTowards.generated.h"


/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTTask_AimTowards : public UBTTask_BaseBlackboardTask
{
	GENERATED_BODY()
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
