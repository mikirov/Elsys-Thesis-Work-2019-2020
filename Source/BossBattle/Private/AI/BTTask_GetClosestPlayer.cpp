// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetClosestPlayer.h"


#include "Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include <limits>

#include "Characters/PlayerCharacter.h"
#include "Characters/PlayerCharacterController.h"
#include "Gamemodes/PlayingGameMode.h"
#include "Utilities/CustomMacros.h"

EBTNodeResult::Type UBTTask_GetClosestPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	APlayerCharacter* PlayerCharacter = GetClosestPlayerCharacter();
	if (IsValid(PlayerCharacter)) {
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), PlayerCharacter);
		return EBTNodeResult::Succeeded;

	}
	else {
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);
		return EBTNodeResult::Failed;
	}

}

APlayerCharacter* UBTTask_GetClosestPlayer::GetClosestPlayerCharacter()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return nullptr; }

	APlayerCharacter* ChosenPlayerCharacter = nullptr;
	float CurrentDistance = std::numeric_limits<float>::max();

	APlayingGameMode* GameMode = Cast<APlayingGameMode>(World->GetAuthGameMode());
	if (validate(IsValid(GameMode)) == false) return nullptr;

	TArray<APlayerCharacterController*> Controllers = GameMode->GetPlayerControllers();
	for (APlayerCharacterController* PlayerController : Controllers) {
		if (validate(IsValid(PlayerController)) == false) { continue; }

		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerController->GetPawn());
		if (IsValid(PlayerCharacter) == false) { continue; }

		float DistanceToPlayer = FVector::Dist(PlayerCharacter->GetActorLocation(), AICharacter->GetActorLocation());
		if (DistanceToPlayer < CurrentDistance) {
			ChosenPlayerCharacter = PlayerCharacter;
			CurrentDistance = DistanceToPlayer;
		}
	}


	return ChosenPlayerCharacter;
}
