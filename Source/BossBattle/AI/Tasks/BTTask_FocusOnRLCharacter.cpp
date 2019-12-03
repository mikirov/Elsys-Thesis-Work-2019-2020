// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FocusOnRLCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "AIController.h"

#include "Utilities/CustomMacros.h"
#include "Characters/RLEnemyCharacter.h"

EBTNodeResult::Type UBTTask_FocusOnRLCharacter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	TArray<AActor*> Results;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARLEnemyCharacter::StaticClass(), Results);

	for (AActor* Result : Results) {
		AIController->SetFocus(Result);
	}
	return EBTNodeResult::Succeeded;
}
