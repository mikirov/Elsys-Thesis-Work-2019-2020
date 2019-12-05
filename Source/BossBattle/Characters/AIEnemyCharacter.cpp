// Fill out your copyright notice in the Description page of Project Settings.


#include "AIEnemyCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

#include "Components/CapsuleComponent.h"
#include "Gamemodes/BossBattleGameMode.h"
#include "Gamemodes/TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/HealthComponent.h"
#include "Characters/RLEnemyCharacter.h"


// Sets default values
AAIEnemyCharacter::AAIEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}




void AAIEnemyCharacter::SetTarget(AActor* TargetToSet) {
	if (validate(IsValid(TargetToSet)) == false) { return; }

	Target = TargetToSet;
}

void AAIEnemyCharacter::Reset() {
	//TODO:implement
	SetActorTransform(InitialTransform);
	HealthComponent->ResetHealth();

	UBlackboardComponent* BlackboardComponent = UAIBlueprintHelperLibrary::GetBlackboard(this);
	if (validate(IsValid(BlackboardComponent)) == false) return;

	BlackboardComponent->ClearValue(FName("TakingHits"));
	BlackboardComponent->ClearValue(FName("CriticalHealth"));
	BlackboardComponent->ClearValue(FName("EnemyHeard"));
	BlackboardComponent->ClearValue(FName("CanSeeRLCharacter"));
	BlackboardComponent->ClearValue(FName("MoveLocation"));


}

void AAIEnemyCharacter::BeginPlay() {
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	InitialTransform = GetActorTransform();

	//ATrainingGameMode* GameMode = Cast<ATrainingGameMode>(World->GetAuthGameMode());
	//if (validate(IsValid(GameMode)) == false) { return; }
	//GameMode->SetAISpawnTransform(InitialTransform);

	HealthComponent->OnHealthChanged.AddDynamic(this, &AAIEnemyCharacter::OnTakingDamage);

}

void AAIEnemyCharacter::OnTakingDamage(int CurrentHealth) {
	UBlackboardComponent* BlackboardComponent = UAIBlueprintHelperLibrary::GetBlackboard(this);
	if (validate(IsValid(BlackboardComponent)) == false) return;

	BlackboardComponent->SetValueAsBool(FName("TakingHits"), true);
	if (CurrentHealth < HealthComponent->GetMaxHealth() / 3) {
		BlackboardComponent->SetValueAsBool(FName("CriticalHealth"), true);

	}
	ARLEnemyCharacter* RLCharacter =  Cast<ARLEnemyCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ARLEnemyCharacter::StaticClass()));
	if (validate(IsValid(RLCharacter)) == false) return;
		
	RLCharacter->UpdateStateAction(false, false);

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAIEnemyCharacter::ClearTakingHits, 0.0f, false, 0.25f);
	

}

void AAIEnemyCharacter::ClearTakingHits() {
	UBlackboardComponent* BlackboardComponent = UAIBlueprintHelperLibrary::GetBlackboard(this);
	if (validate(IsValid(BlackboardComponent)) == false) return;

	BlackboardComponent->SetValueAsBool(FName("TakingHits"), false);

}

void AAIEnemyCharacter::Die() {
	Super::Die();
	
	
	if (HasAuthority()) {
		AController* EnemyController;
		EnemyController = GetController();
		if (validate(IsValid(EnemyController)) == false) { return; }

		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }

		EnemyController->StopMovement();
		EnemyController->Destroy();

		ABossBattleGameMode* BossBattleGameMode = Cast<ABossBattleGameMode>(World->GetAuthGameMode());
		if (IsValid(BossBattleGameMode)) {
			BossBattleGameMode->IncrementScore(Score);
			BossBattleGameMode->DecrementEnemyCounter();
			return;
		}

		ATrainingGameMode* TrainingGameMode = Cast<ATrainingGameMode>(World->GetAuthGameMode());
		if (IsValid(TrainingGameMode)) {
			//TODO: perhaps add death timer
			TrainingGameMode->ResetCharacters(true);
			//ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ARLEnemyCharacter::StaticClass()));
			//if (validate(IsValid(RLCharacter)) == false) return;

			//RLCharacter->UpdateStateAction(true, false);

			return;
		}

	}

	SetActorEnableCollision(false);
	UCapsuleComponent* Capsule;
	Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule)) == false) { return; }
	Capsule->SetEnableGravity(false);
}
