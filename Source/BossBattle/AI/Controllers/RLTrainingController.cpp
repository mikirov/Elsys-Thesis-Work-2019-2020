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


#include "Characters/HealthComponent.h"
#include "Characters/RLEnemyCharacter.h"
#include "Gamemodes/TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Utilities/Action.h"
#include "Characters/AIEnemyCharacter.h"
#include "AI/Controllers/EnemyAIController.h"
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

	ShowTable(QTable);

	UTrainingSaveGame* SaveGameInstance = Cast<UTrainingSaveGame>(UGameplayStatics::CreateSaveGameObject(UTrainingSaveGame::StaticClass()));
	if (validate(IsValid(SaveGameInstance)) == false) return;

	// Set data on the savegame object.
	SaveGameInstance->TakingDamageReward = TakingDamageReward;
	SaveGameInstance->DealingDamageReward = DealingDamageReward;
	SaveGameInstance->KillReward = KillReward;
	SaveGameInstance->DeathReward = DeathReward;
	SaveGameInstance->Epsilon = Epsilon;
	SaveGameInstance->LearningRate = LearningRate;
	SaveGameInstance->AliveReward = AliveReward;
	SaveGameInstance->CriticalHealthRewardMultiplier = CriticalHealthRewardMultiplier;


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

	//UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::GetReward()"))
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return 0.0f;

	//AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass()));
	//if (validate(IsValid(AICharacter)) == false) return 0.0f;
	
	bool bHittingAICharacter = false;
	bool bKilledAICharacter = false;
	bDealingDamage = false;


	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(World, AAIEnemyCharacter::StaticClass(), OutActors);
	for (AActor* Actor : OutActors) {
		AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(Actor);
		if (validate(IsValid(AICharacter)) == false) return 0.0f;

		if (AICharacter->IsTakingDamage()) {
			bHittingAICharacter = true;
			bDealingDamage = true;
		}
		if (AICharacter->IsDead()) {
			bKilledAICharacter = true;
		}
	}

	
	bDealingDamage = bHittingAICharacter;

	ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(GetPawn());
	if (validate(IsValid(RLCharacter)) == false) return 0.0f;

	float Reward = 0.0f;
	if (bKilledAICharacter) {
		Reward += KillReward;
	}
	if (RLCharacter->IsDead()) {
		Reward += DeathReward;
	}
	if (RLCharacter->IsTakingDamage()) {
		Reward += TakingDamageReward;
	}
	if (bHittingAICharacter) {
		Reward += DealingDamageReward;
	}

	if (RLCharacter->IsOnCriticalHealth()) {
		Reward += (TimeAlive * AliveReward * CriticalHealthRewardMultiplier);
	}
	return Reward;
}

void ARLTrainingController::ResetTable()
{

	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::ResetTable"))

	for (int i = 0; i < StateCount; i++) {
		for (int j = 0; j < Actions.size(); j++) {
			QTable[i][j] = 0.0f;
		}
	}

	SerializeTable(QTable);

	ShowTable(QTable);
}


void ARLTrainingController::OnPossess(APawn* InPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::OnPossess(APawn* InPawn)"))

	Super::OnPossess(InPawn);

	FString SaveSlotName = "Training";

	UTrainingSaveGame* LoadedGame = Cast<UTrainingSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (validate(LoadedGame) != false) {
		TakingDamageReward = LoadedGame->TakingDamageReward;
		DealingDamageReward = LoadedGame->DealingDamageReward;
		KillReward = LoadedGame->KillReward;
		AliveReward = LoadedGame->AliveReward;
		DeathReward = LoadedGame->DeathReward;
		Epsilon = LoadedGame->Epsilon;
		LearningRate = LoadedGame->LearningRate;
		CriticalHealthRewardMultiplier = LoadedGame->CriticalHealthRewardMultiplier;
	}

	//ShowTable(QTable);

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
		if (validate(CurrentActionIndex >= 0 && CurrentActionIndex < Actions.size()) == false) return;

	}

	//find the previous action value
	if (validate(PreviousActionIndex >= 0 && PreviousActionIndex < Actions.size()) == false) return;
	float PreviousActionValue = QTable[PreviousStateIndex][PreviousActionIndex];

	//update the previous action value
	PreviousActionValue = PreviousActionValue + LearningRate * (CurrentReward + (DiscountFactor * CurrentActionValue) - PreviousActionValue);

	QTable[PreviousStateIndex][PreviousActionIndex] = PreviousActionValue;

	//ShowTable(QTable);

	//taking the current action
	TakeAction(CurrentActionIndex);
}
