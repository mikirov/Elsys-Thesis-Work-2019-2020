// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveNearRLCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTask_MoveNearRLCharacter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}


	TArray<AActor*> Results;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), Results);

	for (AActor* Result : Results) {
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Result);
		if (PlayerCharacter == nullptr) {
			BlackboardComponent->ClearValue(FName("CanSeeRLCharacter"));
			return EBTNodeResult::Succeeded;
		}
		else {
			//TODO: Get random point in radius and set it
			FNavLocation ResultLocation;

			//FIXME: nav system getter not working

			//UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
			//if (validate(IsValid(NavSys)) == false) return EBTNodeResult::Failed;


			//bool bSuccess = NavSys->GetRandomPointInNavigableRadius(PawnLocation, 6000, ResultLocation);
			//if (bSuccess == false) {
			//	return EBTNodeResult::Failed;
			//}
			//
			//BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), ResultLocation);
		}
	}


	BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);

	return EBTNodeResult::Succeeded;

}
