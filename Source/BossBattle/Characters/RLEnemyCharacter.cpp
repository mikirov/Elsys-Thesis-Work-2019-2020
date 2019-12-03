// Fill out your copyright notice in the Description page of Project Settings.


#include "RLEnemyCharacter.h"

#include "TimerManager.h"
#include "Engine/World.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Characters/HealthComponent.h"
#include "Gamemodes/TrainingGameMode.h"
#include "Utilities//CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"

void ARLEnemyCharacter::Reset() {
	//TODO: implement
	SetActorTransform(InitialTransform);
	HealthComponent->ResetHealth();
	
	bSeeEnemy = false;
	bHearsNoise = false;
	bHittingAICharacter = false;
	bTakingDamage = false;

	ClearFocus();

	ServerStopFiring();

	UpdateStateAction(false, false);

}


void ARLEnemyCharacter::UpdateStateAction(bool bDidKill, bool bDidDie) {

	//set value of hitting AI character flag
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	AActor* AICharacter = UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass());

	UBlackboardComponent* BlackboardComponent = UAIBlueprintHelperLibrary::GetBlackboard(AICharacter);
	if (validate(IsValid(BlackboardComponent)) == false) return;

	bHittingAICharacter = BlackboardComponent->GetValueAsBool(FName("TakingHits"));

	//calculate the reward to be added to previous state
	CurrentReward = 0.0f;
	if (bDidKill == true) {
		CurrentReward = 1.0f;
	}
	else if (bDidDie == true)
	{
		CurrentReward = -1.0f;
	}
	else if (bTakingDamage == true)
	{
		CurrentReward = TakingDamagePenalty;
	}
	else if (bHittingAICharacter == true)
	{
		CurrentReward = -TakingDamagePenalty;
	}

	CurrentState.Append(CurrentAction);

	PreviousStateAction = CurrentState;

	//Clears the CurrentState string, the StateStringArray, the MaxStateValues Map, & the ActionValues float Array

	CurrentState = FString("");
	StateStringArray.Empty();
	MaxStateValues.Empty();
	StateActionStrings.Empty();
	ActionValues.Empty();

	//Determines the next state by adding 1's or 0's to a string array based on whether each flag was true or false.
	bTakingDamage ? StateStringArray.Add(FString("1")) : StateStringArray.Add(FString("0"));
	bSeeEnemy ? StateStringArray.Add(FString("1")) : StateStringArray.Add(FString("0"));
	bHearsNoise ? StateStringArray.Add(FString("1")) : StateStringArray.Add(FString("0"));
	HealthComponent->GetHealth / HealthComponent->GetMaxHealth() / 3 ? StateStringArray.Add(FString("1")) : StateStringArray.Add(FString("0"));
	bHittingAICharacter ? StateStringArray.Add(FString("1")) : StateStringArray.Add(FString("0"));

	//FIXME
	CurrentState = FString::Join(StateStringArray, "");

	//create possible state action strings
	CurrentState.Append(FString("0")); //TODO: check if it should return a new copy
	StateActionStrings.Add(CurrentState);

	if (bSeeEnemy || bHearsNoise) {
		CurrentState.Append(FString("1")); //TODO: check if it should return a new copy
		StateActionStrings.Add(CurrentState);

	}
	CurrentState.Append(FString("1")); //TODO: check if it should return a new copy
	StateActionStrings.Add(CurrentState);

	// Determines the float value of each state-action string. If there is none, create one that is set to 0.
	for (const FString& StateAction : StateActionStrings) {
		if (StateTable.Contains(StateAction)) {
			ActionValues.Add(*StateTable.Find(StateAction));
		}
		else {
			StateTable.Add(StateAction, 0.0f);
			ActionValues.Add(0.0f);
		}
	}

	bRandomAction = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f) < Epsilon;
	//Chooses an action randomly based on Epsilon. 
	if (bRandomAction == true) {
		int RandomNumber = UKismetMathLibrary::RandomIntegerInRange(0, StateActionStrings.Num() - 1);

		CurrentAction = FString::FromInt(RandomNumber);
		NextStateActionValue = ActionValues[RandomNumber];
	}
	//Creates an array of each state-action string that had the highest value
	else {
		int OutIndex;
		float OutValue;
		UKismetMathLibrary::MaxOfFloatArray(ActionValues, OutIndex, OutValue);
		MaxStateValues.Add(FString::FromInt(OutIndex), OutValue);

		NextStateActionValue = OutValue;

		for (int i = 0; i < ActionValues.Num(); i++) {
			if (ActionValues[i] <= NextStateActionValue) {
				MaxStateValues.Add(FString::FromInt(i), ActionValues[i]);
			}
		}
		TArray<FString> MaxStateKeys;
		MaxStateValues.GetKeys(MaxStateKeys);
		CurrentAction = MaxStateKeys[UKismetMathLibrary::RandomIntegerInRange(0, MaxStateKeys.Num() - 1)];
	}

	// TD-Learning algorithm to update the value for the previous action

	float FoundActionValue = *StateTable.Find(PreviousStateAction);

	FoundActionValue += ((FoundActionValue - (DiscountFactor * NextStateActionValue)) + CurrentReward) * LearningRate;
	StateTable.Add(PreviousStateAction, FoundActionValue);

	//performs actions
	FTimerHandle MoveTimerHandle;
	if (CurrentAction.Equals(FString("0"))) {
		GetWorldTimerManager().SetTimer(MoveTimerHandle, this, &ARLEnemyCharacter::MoveNearAICharacter, 0.0f, true, 1.0f);
	}
	else if (CurrentAction.Equals(FString("1"))) {
		GetWorldTimerManager().ClearTimer(MoveTimerHandle);
		ShootAICharacter();
	}
	else if (CurrentAction.Equals(FString("2"))) {
		GetWorldTimerManager().ClearTimer(MoveTimerHandle);
		
		ServerStopFiring();
		
		ClearFocus();

		//TODO: find and move to hiding location
	}


}

void ARLEnemyCharacter::IncrementKillScore() {
	Kills += 1;
}

int ARLEnemyCharacter::GetKills() const{
	return Kills;
}

void ARLEnemyCharacter::BeginPlay() {
	Super::BeginPlay();

	InitialTransform = GetActorTransform();

	HealthComponent->OnHealthChanged.AddDynamic(this, &ARLEnemyCharacter::OnHealthChanged);
	
}

void ARLEnemyCharacter::OnHealthChanged(int CurrentHealth) {

	
	bTakingDamage = true;
	//TODO: make sure bDead is actually working as expected
	if (bDead == false) {
		UpdateStateAction(false, false);

		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ARLEnemyCharacter::ClearTakingDamage, 0.0f, false, 0.25f);

	}

}

void ARLEnemyCharacter::ClearFocus() {
	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	AIController->ClearFocus(EAIFocusPriority::Gameplay);
}

void ARLEnemyCharacter::ShootAICharacter() {
	//focus on AI character
	FocusOnAICharacter();

	//Move near AI character
	MoveNearAICharacter();

	//Shoot Weapon
	ServerStartFiring();


}

void ARLEnemyCharacter::ReportNoise() {
	this->PawnMakeNoise(1.0f, FVector(0, 0, 0), true, this);

}

void ARLEnemyCharacter::MoveNearAICharacter() {

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	AActor* AICharacter = UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass());

	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(World);
	if (validate(IsValid(NavigationSystem)) == false) return;

	//FVector Result = NavigationSystem->GetRandomPointInNavigableRadius(World, AICharacter->GetActorLocation(), 600);
	FNavLocation Result;
	NavigationSystem->GetRandomPointInNavigableRadius(AICharacter->GetActorLocation(), 600, Result);
	
	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	AIController->MoveToLocation(Result);
	

}

void ARLEnemyCharacter::FocusOnAICharacter() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	AActor* AICharacter = UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass());

	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	AIController->SetFocus(AICharacter);
}

void ARLEnemyCharacter::ClearTakingDamage() {
	bTakingDamage = false;
	UpdateStateAction(false, false);
}

void ARLEnemyCharacter::Die() {
	Super::Die();


	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }


	bDead = true;

	UpdateStateAction(false, true);

	ATrainingGameMode* TrainingGameMode = Cast<ATrainingGameMode>(World->GetAuthGameMode());
	if (IsValid(TrainingGameMode)) {
		//TODO: perhaps add death timer
		TrainingGameMode->ResetCharacters(false);
		return;
	}
	//TODO: implement

}
