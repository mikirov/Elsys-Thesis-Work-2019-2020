// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_AimTowards.h"

#include "Kismet/KismetMathLibrary.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

#include "Utilities/CustomMacros.h"


EBTNodeResult::Type UBTTask_AimTowards::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	APawn* TargetCharacter = Cast<APawn>(BlackboardComponent->GetValueAsObject(GetSelectedBlackboardKey()));
	if (validate(IsValid(TargetCharacter)) == false) return EBTNodeResult::Failed;
	
	
	FVector TargetLocation = TargetCharacter->GetActorLocation();
	

	FVector StartLocation = AICharacter->GetActorLocation();
	
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		StartLocation,
		TargetLocation
	);

	AICharacter->SetActorRotation(FRotator(0, LookAtRotation.Yaw, 0));

	AIController->SetControlRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));

	return EBTNodeResult::Succeeded;
}
