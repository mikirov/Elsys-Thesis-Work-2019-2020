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
#include "Utilities/CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"
#include "AI/Controllers/EnemyAIController.h"

void ARLEnemyCharacter::Reset() {
	//TODO: implement
	SetActorTransform(InitialTransform);
	HealthComponent->ResetHealth();
	
	bSeeEnemy = false;
	bHearsNoise = false;
	bDealingDamage = false;
	bTakingDamage = false;

	ClearFocus();

	ServerStopFiring();

	UpdateStateAction(false, false);

}


void ARLEnemyCharacter::MoveForward(float Value)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, 1.0f);
	}
}

void ARLEnemyCharacter::MoveRight(float Value)
{
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}


void ARLEnemyCharacter::UpdateStateAction(bool bDidKill, bool bDidDie) {

	//set value of hitting AI character flag
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass()));
	if (validate(IsValid(AICharacter)) == false) return;
	bDealingDamage = AICharacter->IsTakingDamage();


	//set reward based on current flags
	CurrentReward = bDidKill ? KillReward : (bDidDie ? DeathReward : (bTakingDamage ? TakingDamageReward: (bDealingDamage ? DealingDamageReward : 0.0f)));

	PreviousStateAction = CurrentState + CurrentAction;

	//Clears the CurrentState string, the StateStringArray, the MaxStateValues Map, & the ActionValues float Array
	CurrentState = FString("");
	StateStringArray.Empty();
	MaxStateValues.Empty();
	StateActionStrings.Empty();
	ActionValues.Empty();

	//Determines the next state by adding 1's or 0's to the current state based on whether each flag was true or false.
	CurrentState += bTakingDamage ? "1" : "0";
	CurrentState += HealthComponent->GetHealth() < (HealthComponent->GetMaxHealth() / 3.0f) ? "1" : "0";
	CurrentState += bDealingDamage ? "1" : "0";
	//TODO: make sure RL character can set hearing and sight flags properly
	//CurrentState += bSeeEnemy ? "1" : "0";
	//CurrentState += bHearsNoise ? "1" : "0";

	//create possible state action strings
	//TODO: remove magic number
	for (int i = 0; i < 6; i++) {
		StateActionStrings.Add(CurrentState + FString::FromInt(i));
	}
	//StateActionStrings.Add(CurrentState + "0");
	//StateActionStrings.Add(CurrentState + "1");
	//StateActionStrings.Add(CurrentState + "2");

	//use this state only if we can hear or see enemy
	//if (bSeeEnemy || bHearsNoise) {
	//	StateActionStrings.Add(CurrentState + "1");
	//}


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
		//MaxStateValues.Add(FString::FromInt(OutIndex), OutValue);

		//NextStateActionValue = OutValue;

		//for (int i = 0; i < ActionValues.Num(); i++) {
		//	if (ActionValues[i] <= NextStateActionValue) {
		//		MaxStateValues.Add(FString::FromInt(i), ActionValues[i]);
		//	}
		//}
		//TArray<FString> MaxStateKeys;
		//MaxStateValues.GetKeys(MaxStateKeys);
		//CurrentAction = MaxStateKeys[UKismetMathLibrary::RandomIntegerInRange(0, MaxStateKeys.Num() - 1)];
		CurrentAction = FString::FromInt(OutIndex);
	}

	// TD-Learning algorithm to update the value for the previous action

	float* FoundActionValuePointer = StateTable.Find(PreviousStateAction);
	if (FoundActionValuePointer != nullptr){

		float FoundActionValue = *FoundActionValuePointer;

		FoundActionValue += (((DiscountFactor * NextStateActionValue) - FoundActionValue) + CurrentReward) * LearningRate;
		StateTable.Add(PreviousStateAction, FoundActionValue);

	}

	
	//performs actions
	FTimerHandle MoveTimerHandle;

	switch (FCString::Atoi(*CurrentAction))
	{
		//move forward
		case 0:

			ServerStopFiring();
			MoveForward(1.0f);
			break;
		
		//move back
		case 1:
			ServerStopFiring();
			MoveForward(-1.0f);
			break;

		//move left
		case 2:
			ServerStopFiring();
			MoveRight(-1.0f);
			break;

		//move right
		case 3:
			ServerStopFiring();
			MoveRight(1.0f);
			break;

		//aim towards enemy
		case 4:
			ServerStopFiring();
			FocusOnAICharacter();
			break;

		//shoot
		case 5:
			ServerStartFiring();
			break;
		default:
			validate(false);
			break;
	}

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

void ARLEnemyCharacter::BeginPlay() {
	Super::BeginPlay();

	InitialTransform = GetActorTransform();

	HealthComponent->OnHealthChanged.AddDynamic(this, &ARLEnemyCharacter::OnHealthChanged);
	
}

void ARLEnemyCharacter::OnHealthChanged(int CurrentHealth) {

	
	bTakingDamage = true;
	bCriticalHealth = (CurrentHealth < HealthComponent->GetMaxHealth() / 3);
	

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
	this->PawnMakeNoise(1.0f, GetActorLocation(), true, this);
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
	if(validate(IsValid(AICharacter) == false)) return;

	AAIController* AIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (validate(IsValid(AIController)) == false) return;

	//AIController->SetFocus(AICharacter);

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		GetActorLocation(),
		AICharacter->GetActorLocation()
	);

	AICharacter->SetActorRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));

	AIController->SetControlRotation(FRotator(LookAtRotation.Pitch, LookAtRotation.Yaw, 0));
}

void ARLEnemyCharacter::ClearTakingDamage() {
	bTakingDamage = false;
	UpdateStateAction(false, false);
}

void ARLEnemyCharacter::ResetCharacters() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	ATrainingGameMode* TrainingGameMode = Cast<ATrainingGameMode>(World->GetAuthGameMode());
	if (validate(IsValid(TrainingGameMode))) {
		
		TrainingGameMode->ResetCharacters(false);
		return;
	}

}

void ARLEnemyCharacter::Die() {
	Super::Die();

	bDead = true;

	UpdateStateAction(false, true);

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ARLEnemyCharacter::ResetCharacters, 0.0f, false, 3.0f);

}
