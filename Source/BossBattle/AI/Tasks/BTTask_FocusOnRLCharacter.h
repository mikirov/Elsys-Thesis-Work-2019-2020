// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Tasks/BTTask_BaseNode.h"
#include "BTTask_FocusOnRLCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTTask_FocusOnRLCharacter : public UBTTask_BaseNode
{
	GENERATED_BODY()


	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
