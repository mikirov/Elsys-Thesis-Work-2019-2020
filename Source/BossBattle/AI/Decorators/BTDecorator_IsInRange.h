// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTDecorator_IsInRange.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTDecorator_IsInRange : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float TargetDistance = 500.0f;

protected:
	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
