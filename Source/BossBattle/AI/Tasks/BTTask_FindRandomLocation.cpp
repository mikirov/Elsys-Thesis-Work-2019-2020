// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandomLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Utilities/CustomMacros.h"

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	
	APawn* Pawn = nullptr;
	Pawn = AIController->GetPawn();
	if (validate(IsValid(Pawn)) == false) return EBTNodeResult::Failed;

	FVector PawnLocation = Pawn->GetActorLocation();

	FNavLocation ResultLocation;

	//FIXME: nav system getter not working

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (validate(IsValid(NavSys)) == false) return EBTNodeResult::Failed;


	bool bSuccess = NavSys->GetRandomPointInNavigableRadius(PawnLocation, 6000, ResultLocation);
	if (bSuccess == false) {
		return EBTNodeResult::Failed;
	}
	
	BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), ResultLocation);


	return EBTNodeResult::Succeeded;
}