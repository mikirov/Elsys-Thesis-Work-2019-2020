// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_AimTowards.h"

#include "Kismet/KismetMathLibrary.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"

#include "Utilities/CustomMacros.h"
#include "Characters/BattleCharacter.h"


EBTNodeResult::Type UBTTask_AimTowards::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	ABattleCharacter* TargetCharacter = Cast<ABattleCharacter>(BlackboardComponent->GetValueAsObject(GetSelectedBlackboardKey()));
	if (validate(IsValid(TargetCharacter)) == false) return EBTNodeResult::Failed;
	
	
	FVector TargetLocation = TargetCharacter->GetActorLocation();
	if (IsValid(TargetCharacter)) {
		float EyeHeight = TargetCharacter->bIsCrouched ? TargetCharacter->CrouchedEyeHeight : TargetCharacter->BaseEyeHeight;
		TargetLocation += FVector(0, 0, EyeHeight);	
	}

	FRotator LookAtRotation = AICharacter->GetAimAtRotation(TargetLocation);

	AICharacter->SetActorRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));

	AIController->SetControlRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));

	return EBTNodeResult::Succeeded;
}
