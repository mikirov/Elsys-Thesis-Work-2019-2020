// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRLCharacter.h"


#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"

EBTNodeResult::Type UBTTask_GetRLCharacter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	ARLEnemyCharacter* RLCharacter = GetRLCharacter();
	if (RLCharacter != nullptr) {
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), RLCharacter);
		return EBTNodeResult::Succeeded;

	}
	else {
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);
		return EBTNodeResult::Failed;
	}

}

ARLEnemyCharacter* UBTTask_GetRLCharacter::GetRLCharacter() {
	
	
	
	ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ARLEnemyCharacter::StaticClass()));
	if (validate(IsValid(RLCharacter)) == false) return nullptr;

	return RLCharacter;



}