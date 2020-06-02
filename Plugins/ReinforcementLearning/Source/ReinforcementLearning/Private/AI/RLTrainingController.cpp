// Fill out your copyright notice in the Description page of Project Settings.


#include "RLTrainingController.h"


#include "TimerManager.h"
#include "Engine/World.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


#include "Utilities/CustomMacros.h"
#include "Action.h"
#include "State.h"


#include "TrainingGameMode.h"
#include "Utilities/TrainingSaveGame.h"


void ARLTrainingController::UpdateStepAndEpisode()
{

	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::UpdateStepAndEpisode()"))
		StepsThisEpisode++;
	if (StepsThisEpisode == StepsPerEpisode) {
		Episode++;

		SerializeTable(QTable);

		StepsThisEpisode = 0;
	}
}


void ARLTrainingController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	SerializeTable(QTable);


	UTrainingSaveGame* SaveGameInstance = Cast<UTrainingSaveGame>(UGameplayStatics::CreateSaveGameObject(UTrainingSaveGame::StaticClass()));
	if (validate(IsValid(SaveGameInstance)) == false) return;

	//serialize parameters
	SaveGameInstance->Epsilon = Epsilon;
	SaveGameInstance->LearningRate = LearningRate;
	SaveGameInstance->DelayFrames = DelayFrames;
	SaveGameInstance->ActionFailReward = ActionFailReward;


	FString SaveSlotName = "Training";
	// Save the data immediately.
	if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveSlotName, 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveSlotName, 0)"))
			// Save succeeded.
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveSlotName, 0) == false"))

	}


	Super::EndPlay(EndPlayReason);

}

float ARLTrainingController::GetReward()
{

	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::GetReward()"))
	float TotalReward = bLastActionSuccess ? ActionFailReward : 0.0f;

	//get rewards for satisfied states
	for (int i = 0; i < States.Num(); i++) {
		TotalReward += States[i]->GetReward();
	}

	return TotalReward;

}

void ARLTrainingController::ResetTable()
{

	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::ResetTable"))

		for (int i = 0; i < States.Num(); i++) {
			for (int j = 0; j < Actions.Num(); j++) {
				QTable[i][j] = 0.0f;
			}
		}

	SerializeTable(QTable);

}


void ARLTrainingController::OnPossess(APawn* InPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::OnPossess(APawn* InPawn)"))

	Super::OnPossess(InPawn);


	FString SaveSlotName = "Training";
	UTrainingSaveGame* SaveGameInstance = Cast<UTrainingSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	
	if (validate(IsValid(SaveGameInstance))) {
		Epsilon = SaveGameInstance->Epsilon;
		LearningRate = SaveGameInstance->LearningRate;
		DelayFrames = SaveGameInstance->DelayFrames;
		ActionFailReward = SaveGameInstance->ActionFailReward;
	}
	

}

//we will use the tick method for every step 
void ARLTrainingController::Tick(float DeltaTime)
{


	if (bPossessed == false) return;

	TimeAlive += DeltaTime;


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
		if (validate(CurrentActionIndex >= 0 && CurrentActionIndex < Actions.Num()) == false) return;

	}

	//find the previous action value
	if (validate(PreviousActionIndex >= 0 && PreviousActionIndex < Actions.Num()) == false) return;
	float PreviousActionValue = QTable[PreviousStateIndex][PreviousActionIndex];

	//update the previous action value
	PreviousActionValue = PreviousActionValue + LearningRate * (CurrentReward + (DiscountFactor * CurrentActionValue) - PreviousActionValue);

	QTable[PreviousStateIndex][PreviousActionIndex] = PreviousActionValue;

	
	//taking the current action
	TakeAction(CurrentActionIndex);
}
