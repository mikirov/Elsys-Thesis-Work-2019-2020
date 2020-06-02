// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRLCharacter.h"


#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "CustomMacros.h"
#include "LearningComponent.h"

EBTNodeResult::Type UBTTask_GetRLCharacter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	AActor* RLCharacter = GetRLCharacter();
	if (RLCharacter != nullptr) {
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), RLCharacter);
		return EBTNodeResult::Succeeded;

	}
	else {
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);
		return EBTNodeResult::Failed;
	}

}

AActor* UBTTask_GetRLCharacter::GetRLCharacter() {
	

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return nullptr;

	TArray<AActor*> ResultActors;
	UGameplayStatics::GetAllActorsOfClass(World, APawn::StaticClass(), ResultActors);

	//there should be only one learning component in the whole game and it shouuld be on the actor being trained
	for (auto Pawn : ResultActors) {
		ULearningComponent* LearningComponent = Cast<ULearningComponent>(Pawn->GetComponentByClass(ULearningComponent::StaticClass()));
		if (IsValid(LearningComponent)) {
			return Pawn;
		}
	}

	return nullptr;



}