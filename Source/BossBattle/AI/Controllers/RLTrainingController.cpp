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
#include "Characters/AIEnemyCharacter.h"
#include "AI/Controllers/EnemyAIController.h"
#include "Utilities/TableSaveGame.h"

void ARLTrainingController::ShowTable()
{
	FString Result = "QTable:\n==========";

		for (auto& Pair : QTable)
		{
			Result += "{State:" + FString::FromInt(Pair.Key) + " Actions : [";
			for (auto& Value : Pair.Value.ActionValues) {
				Result += FString::SanitizeFloat(Value) + ", ";
			}
			Result += "]\n";
			
		}
		Result += "==========";
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Result)

}


void ARLTrainingController::SaveTable(int EpisodeToSet)
{
	UTableSaveGame* SaveGameInstance = Cast<UTableSaveGame>(UGameplayStatics::CreateSaveGameObject(UTableSaveGame::StaticClass()));
	if (validate(IsValid(SaveGameInstance)) == false) return;

	FAsyncSaveGameToSlotDelegate SavedDelegate;
	// USomeUObjectClass::SaveGameDelegateFunction is a void function that takes the following parameters: const FString& SlotName, const int32 UserIndex, bool bSuccess
	SavedDelegate.BindUObject(this, &ARLTrainingController::OnTableSaved);

	// Set data on the save game object.
	SaveGameInstance->QTable = QTable;
	SaveGameInstance->Episode = EpisodeToSet;

	// Start async save process.
	UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, FString::FromInt(0), 0, SavedDelegate);

}


void ARLTrainingController::UpdateStepAndEpisode()
{
	StepsThisEpisode++;
	if (StepsThisEpisode == StepsPerEpisode) {
		Episode++;
		SaveTable(Episode);
		StepsThisEpisode = 0;
	}
}


void ARLTrainingController::OnTableSaved(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	UE_LOG(LogTemp, Warning, TEXT("ARLEnemyCharacter::OnTableSaved"))
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

void ARLTrainingController::BeginPlay()
{
	Super::BeginPlay();

	UTableSaveGame* LoadedTable = Cast<UTableSaveGame>(UGameplayStatics::LoadGameFromSlot(FString::FromInt(0), 0));
	if (validate(IsValid(LoadedTable))) {
		QTable = LoadedTable->QTable;
		Episode = LoadedTable->Episode;
	}

	else {
		//Q-table initialization
		for (int i = 0; i < StateCount; i++) {
			TArray<float> ActionArray;
			for (int j = 0; j < Actions.Num(); j++) {
				ActionArray.Add(0.0f); // set all initial action values to 0
			}
			QTable.Add(i, ActionArray);
		}

	}

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
	validate(CurrentStateIndex >= 0);

	// choosing current action based on the current state. We either take a random action or the best action from the q-table for this step
	// if we don't set a custom epsilon value the random action chance is determined by the episode number
	bRandomAction = FMath::IsNearlyZero(Epsilon) ? FMath::RandRange(0.0f, 1.0f) < (1 / Episode) : FMath::RandRange(0.0f, 1.0f) < Epsilon;
 
	if (bRandomAction == true) {

		CurrentActionIndex = FMath::RandRange(0, 5);

	}
	else {

		GetBestAction(CurrentStateIndex, CurrentActionIndex, CurrentActionValue);
		validate(CurrentActionIndex >= 0);
	}

	//find the previous action value
	struct FActionValues* PreviousActionValuesPointer = QTable.Find(PreviousStateIndex);
	if (validate(PreviousActionValuesPointer != nullptr) == false) return;
	//float PreviousActionValue = (*PreviousActionValuesPointer)[PreviousActionIndex];
	float PreviousActionValue = PreviousActionValuesPointer->ActionValues[PreviousActionIndex];

	//update the previous action value
	PreviousActionValue = PreviousActionValue + LearningRate * (CurrentReward + (DiscountFactor * CurrentActionValue) - PreviousActionValue);

	PreviousActionValuesPointer->ActionValues[PreviousActionIndex] = PreviousActionValue;
	QTable.Add(PreviousStateIndex, *PreviousActionValuesPointer);

	ShowTable();

	//taking the current action
	TakeAction(CurrentActionIndex);
}
