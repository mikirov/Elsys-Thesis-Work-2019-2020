// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingGameMode.h"

#include "Utilities/CustomMacros.h"

#include "Engine/World.h"

#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Utilities/LearningComponent.h"


void ATrainingGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	for (const FTransform& InitialTransform : InitialAITransforms) {

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		APawn* AIPawn = World->SpawnActor<APawn>(AIEnemyTemplate, InitialTransform, SpawnParameters);
		if (validate(IsValid(AIPawn)) == false) return;
		AIPawns.Add(AIPawn);

		ULearningComponent* LearningComponent = Cast<ULearningComponent>(AIPawn->GetComponentByClass(ULearningComponent::StaticClass()));
		if (validate(IsValid(LearningComponent)) == false) return;
		LearningComponent->OnDeath.AddDynamic(this, &ATrainingGameMode::DecrementEnemyCounter);
		LearningComponent->OnReset.AddDynamic(this, &ATrainingGameMode::ResetCharacters);

	}
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	RLPawn = World->SpawnActor<APawn>(RLEnemyTemplate, InitialRLTransform, SpawnParameters);
	if (validate(IsValid(RLPawn)) == false) return;
	
	ULearningComponent* LearningComponent = Cast<ULearningComponent>(RLPawn->GetComponentByClass(ULearningComponent::StaticClass()));
	if (validate(IsValid(LearningComponent)) == false) return;
	LearningComponent->OnDeath.AddDynamic(this, &ATrainingGameMode::ResetCharacters);
	LearningComponent->OnReset.AddDynamic(this, &ATrainingGameMode::ResetCharacters);

	CurrentEnemies = InitialAITransforms.Num();


}



void ATrainingGameMode::DecrementEnemyCounter()
{
	CurrentEnemies--;

	if (CurrentEnemies == 0) {
		ResetCharacters();
	}
}

void ATrainingGameMode::ResetCharacters() {

	UE_LOG(LogTemp, Warning, TEXT("ATrainingGameMode::ResetCharacters"))

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	
	
	//if there are AI or RL pawns alive destroy them	
	for (auto& AIPawn : AIPawns) {
		if (validate(IsValid(AIPawn)) == false) continue;
		AIPawn->Destroy();
	}
	if (validate(IsValid(RLPawn))) {
		RLPawn->Destroy();
	}
	AIPawns.Empty();
	RLPawn = nullptr;

	for (const FTransform& InitialTransform : InitialAITransforms) {

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		APawn* AIPawn = World->SpawnActor<APawn>(AIEnemyTemplate, InitialTransform, SpawnParameters);
		if (validate(IsValid(AIPawn)) == false) return;
		AIPawns.Add(AIPawn);

		ULearningComponent* LearningComponent = Cast<ULearningComponent>(AIPawn->GetComponentByClass(ULearningComponent::StaticClass()));
		if (validate(IsValid(LearningComponent)) == false) return;
		LearningComponent->OnDeath.AddDynamic(this, &ATrainingGameMode::DecrementEnemyCounter);
		LearningComponent->OnReset.AddDynamic(this, &ATrainingGameMode::ResetCharacters);

	}
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	RLPawn = World->SpawnActor<APawn>(AIEnemyTemplate, InitialRLTransform, SpawnParameters);
	if (validate(IsValid(RLPawn)) == false) return;

	ULearningComponent* LearningComponent = Cast<ULearningComponent>(RLPawn->GetComponentByClass(ULearningComponent::StaticClass()));
	if (validate(IsValid(LearningComponent)) == false) return;
	LearningComponent->OnDeath.AddDynamic(this, &ATrainingGameMode::ResetCharacters);
	LearningComponent->OnReset.AddDynamic(this, &ATrainingGameMode::ResetCharacters);


	CurrentEnemies = InitialAITransforms.Num();


}