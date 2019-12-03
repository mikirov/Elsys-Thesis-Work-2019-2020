// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ShootEnemy.h"

EBTNodeResult::Type UBTTask_ShootEnemy::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}
	//if (AICharacter->IsFiring() == false) {
	//	AICharacter->StartFiring();
	//}


	return EBTNodeResult::Succeeded;
}
