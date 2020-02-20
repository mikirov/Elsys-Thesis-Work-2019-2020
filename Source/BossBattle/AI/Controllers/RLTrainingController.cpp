// Fill out your copyright notice in the Description page of Project Settings.


#include "RLTrainingController.h"


#include "TimerManager.h"
#include "Engine/World.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"


#include "Characters/HealthComponent.h"
#include "Characters/RLEnemyCharacter.h"
#include "Gamemodes/TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Utilities/Action.h"
#include "Characters/AIEnemyCharacter.h"
#include "AI/Controllers/EnemyAIController.h"



void ARLTrainingController::ShowTable(float** Table)
{
	//UE_LOG(LogTemp, Warning, TEXT("QTable:\n==========\n"));

	//for (int i = 0; i < StateCount; i++)
	//{
	//	for (int j = 0; j < Actions.size(); j++) {

	//		UE_LOG(LogTemp, Warning, TEXT("State: %d, Action: %f\n"), i, Table[i][j])
	//	}

	//}
	//UE_LOG(LogTemp, Warning, TEXT("==========\n"));
}

void ARLTrainingController::UpdateStepAndEpisode()
{
	StepsThisEpisode++;
	if (StepsThisEpisode == StepsPerEpisode) {
		Episode++;

		SerializeTable(QTable);

		StepsThisEpisode = 0;
	}
}


float ARLTrainingController::GetReward()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return 0.0f;

	AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass()));
	if (validate(IsValid(AICharacter)) == false) return 0.0f;

	bool bHittingAICharacter = AICharacter->IsTakingDamage();
	bool bKilledAICharacter = AICharacter->IsDead();

	ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(GetPawn());
	if (validate(IsValid(RLCharacter)) == false) return 0.0f;

	float Reward = bKilledAICharacter ? KillReward : (RLCharacter->IsDead() ? DeathReward : (RLCharacter->IsTakingDamage() ? TakingDamageReward : (bHittingAICharacter ? DealingDamageReward : 0.0f)));

	return Reward;
}

void ARLTrainingController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UE_LOG(LogTemp, Warning, TEXT("  ARLController::EndPlay"))

		SerializeTable(QTable);

	for (int i = 0; i < StateCount; i++) {
		delete[] QTable[i];
	}
	delete[] QTable;

	for (int i = 0; i < Actions.size(); i++) {
		delete Actions[i];
	}


}

void ARLTrainingController::ResetTable()
{
	for (int i = 0; i < StateCount; i++) {
		for (int j = 0; j < Actions.size(); j++) {
			QTable[i][j] = 0.0f;
		}
	}

	SerializeTable(QTable);
}

ARLTrainingController::ARLTrainingController() : ARLController()
{
}

void ARLTrainingController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ShowTable(QTable);

}

//we will use the tick method for every step 
void ARLTrainingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateStepAndEpisode();

	// update the previous state and action to the current state and action before updating them
	PreviousStateIndex = CurrentStateIndex;
	PreviousActionIndex = CurrentActionIndex;

	// get the reward received this step
	CurrentReward = GetReward();

	CurrentStateIndex = GetState();
	if (validate(CurrentStateIndex >= 0) == false) return;

	// choosing current action based on the current state. We either take a random action or the best action from the q-table for this step
	// if we don't set a custom epsilon value the random action chance is determined by the episode number
	bRandomAction = FMath::IsNearlyZero(Epsilon) ? FMath::RandRange(0.0f, 1.0f) < (1 / Episode) : FMath::RandRange(0.0f, 1.0f) < Epsilon;
 
	if (bRandomAction == true) {

		CurrentActionIndex = FMath::RandRange(0, 5);

	}
	else {

		GetBestAction(CurrentStateIndex, CurrentActionIndex, CurrentActionValue);
		if (validate(CurrentActionIndex >= 0 && CurrentActionIndex < Actions.size()) == false) return;

	}

	//find the previous action value
	if (validate(PreviousActionIndex >= 0 && PreviousActionIndex < Actions.size()) == false) return;
	float PreviousActionValue = QTable[PreviousStateIndex][PreviousActionIndex];

	//update the previous action value
	PreviousActionValue = PreviousActionValue + LearningRate * (CurrentReward + (DiscountFactor * CurrentActionValue) - PreviousActionValue);

	QTable[PreviousStateIndex][PreviousActionIndex] = PreviousActionValue;

	ShowTable(QTable);

	//taking the current action
	TakeAction(CurrentActionIndex);
}
