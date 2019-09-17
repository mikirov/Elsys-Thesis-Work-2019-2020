// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_IsInRange.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"

#include "Utilities/CustomMacros.h"

void UBTDecorator_IsInRange::OnGameplayTaskDeactivated(UGameplayTask& Task)
{

}

void UBTDecorator_IsInRange::OnGameplayTaskActivated(UGameplayTask& Task)
{

}

bool UBTDecorator_IsInRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (validate(IsValid(BlackboardComponent)) == false) return false;

	AAIController* Controller = OwnerComp.GetAIOwner();
	if (validate(IsValid(Controller)) == false) return false;

	AActor* ControlledPawn = Cast<AActor>(Controller->GetPawn());
	if (validate(IsValid(ControlledPawn)) == false) return false;

	AActor* Target = Cast<AActor>(BlackboardComponent->GetValueAsObject(GetSelectedBlackboardKey()));
	if (validate(IsValid(Target)) == false) return false;;

	if (FVector::Dist(ControlledPawn->GetActorLocation(), Target->GetActorLocation()) <= TargetDistance) {
		return true;
	}
	return false;
}
