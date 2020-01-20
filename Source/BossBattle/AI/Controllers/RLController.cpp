// Fill out your copyright notice in the Description page of Project Settings.


#include "RLController.h"


#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Characters/AIEnemyCharacter.h"
#include "Characters/RLEnemyCharacter.h"
#include "Utilities/CustomMacros.h"
#include "Utilities/TableSaveGame.h"

#include "Utilities/MoveForwardAction.h"
#include "Utilities/MoveBackwardAction.h"
#include "Utilities/MoveLeftAction.h"
#include "Utilities/MoveRightAction.h"
#include "Utilities/ShootEnemyAction.h"
#include "Utilities/FocusOnEnemyAction.h"
#include "Utilities/ReloadAction.h"
#include "Utilities/InteractAction.h"

void ARLController::BeginPlay()
{
	Super::BeginPlay();

	ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(GetPawn());
	if (validate(IsValid(RLCharacter)) == false) return;

	Actions.Add(new MoveForwardAction(0, RLCharacter));
	Actions.Add(new MoveBackwardAction(1, RLCharacter));
	Actions.Add(new MoveLeftAction(2, RLCharacter));
	Actions.Add(new MoveRightAction(3, RLCharacter));
	Actions.Add(new FocusOnEnemyAction(4, RLCharacter));
	Actions.Add(new ShootEnemyAction(5, RLCharacter));
	Actions.Add(new InteractAction(6, RLCharacter));
	Actions.Add(new ReloadAction(7, RLCharacter));
}

void ARLController::TakeAction(int ActionIndex)
{
	for (int i = 0; i < Actions.Num(); i++) {
		if (i == Actions[i]->GetId()) {
			Actions[ActionIndex]->Execute();
			break;
		}
	}
}

int ARLController::GetState()
{
	// taking current state
	//get dealing damage flag, the other two flags are calculated on taking damage event
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return -1;

	AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass()));
	bool bDealingDamage = AICharacter->IsTakingDamage();

	ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(GetPawn());
	if (validate(IsValid(RLCharacter)) == false) return -1;


	int CurrentState = (bDealingDamage * 4) + RLCharacter->IsTakingDamage() * 2 + RLCharacter->IsOnCriticalHealth(); // binary flags to integer

	UE_LOG(LogTemp, Warning, TEXT("CurrentState: %d"), CurrentState);
	
	return CurrentState;

}

void ARLController::GetBestAction(const int CurrentState, int& OutCurrentActionIndex, float& OutCurrentActionValue)
{
	struct FActionValues* ActionValueStruct;

	//get current action values for this state
	if (QTable.Contains(CurrentState)) {
		ActionValueStruct = QTable.Find(CurrentState);
		//get the action value that gives us the highest reward from our array
		UKismetMathLibrary::MaxOfFloatArray(ActionValueStruct->ActionValues, OutCurrentActionIndex, OutCurrentActionValue);

	}
	else {
		OutCurrentActionIndex = -1;
		OutCurrentActionValue = 0.0f;
	}

	
}
