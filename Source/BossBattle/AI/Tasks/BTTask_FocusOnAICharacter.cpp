// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FocusOnAICharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "AIController.h"

#include "Utilities/CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"

EBTNodeResult::Type UBTTask_FocusOnAICharacter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	TArray<AActor*> Results;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIEnemyCharacter::StaticClass(), Results);

	for (AActor* Result : Results) {
		AIController->SetFocus(Result);
	}
	return EBTNodeResult::Succeeded;
}
