// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_IsFiring.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

#include "Utilities/CustomMacros.h"
#include "Characters/BattleCharacter.h"

void UBTDecorator_IsFiring::OnGameplayTaskDeactivated(UGameplayTask& Task)
{

}

void UBTDecorator_IsFiring::OnGameplayTaskActivated(UGameplayTask& Task)
{

}

bool UBTDecorator_IsFiring::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (validate(IsValid(BlackboardComponent)) == false) return false;

	AAIController* Controller = OwnerComp.GetAIOwner();
	if (validate(IsValid(Controller)) == false) return false;

	ABattleCharacter* ControlledPawn = Cast<ABattleCharacter>(Controller->GetPawn());
	if (validate(IsValid(ControlledPawn)) == false) return false;

	return ControlledPawn->IsFiring();
}
