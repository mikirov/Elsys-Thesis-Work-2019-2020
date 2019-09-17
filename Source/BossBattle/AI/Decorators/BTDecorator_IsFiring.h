// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsFiring.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTDecorator_IsFiring : public UBTDecorator
{
	GENERATED_BODY()
protected:
	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
