// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsCrouching.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

#include "Utilities/CustomMacros.h"
#include "Characters/BattleCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/PlayerCharacter.h"

void UBTDecorator_IsCrouching::OnGameplayTaskDeactivated(UGameplayTask& Task)
{

}

void UBTDecorator_IsCrouching::OnGameplayTaskActivated(UGameplayTask& Task)
{

}

bool UBTDecorator_IsCrouching::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return false;

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(World, APlayerCharacter::StaticClass(), OutActors);

	for (AActor* Actor : OutActors) {
		ABattleCharacter* Player = Cast<ABattleCharacter>(Actor);
		if (validate(IsValid(Player)) == false) return false;

		if (Player->IsCrouching()) return true;
	}

	return false;

}
