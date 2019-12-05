// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "Characters/RLEnemyCharacter.h"
#include "Characters/AIEnemyCharacter.h"

void ATrainingGameMode::RespawnRLCharacter() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	World->SpawnActor<ARLEnemyCharacter>(RLEnemyTemplate.Get(), RLSpawnTransform, FActorSpawnParameters());

}

void ATrainingGameMode::RespawnAICharacter() {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	AAIEnemyCharacter* AICharacter = World->SpawnActor<AAIEnemyCharacter>(AIEnemyTemplate.Get(), AISpawnTransform, FActorSpawnParameters());
	

}

int ATrainingGameMode::GetAIKills() const {
	return AIKills;
}

int ATrainingGameMode::GetRLKills() const {
	return RLKills;
}

void ATrainingGameMode::ResetCharacters(bool bAICharacterDied) {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;


	if (bAICharacterDied) {
		
		ARLEnemyCharacter* RLEnemyCharacter = Cast<ARLEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, ARLEnemyCharacter::StaticClass()));
		RLEnemyCharacter->Reset();
		RLEnemyCharacter->IncrementKillScore();

		RLEnemyCharacter->UpdateStateAction(true, false);
	
	}
	else {

		AAIEnemyCharacter* AIEnemyCharacter = Cast<AAIEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, AAIEnemyCharacter::StaticClass()));
		AIEnemyCharacter->Reset();
		AIEnemyCharacter->IncrementKillScore();


		ARLEnemyCharacter* RLEnemyCharacter = Cast<ARLEnemyCharacter>(UGameplayStatics::GetActorOfClass(World, ARLEnemyCharacter::StaticClass()));
		RLEnemyCharacter->UpdateStateAction(true, false);

	}

}

FTransform  ATrainingGameMode::GetRLSpawnTransform() const{
	return RLSpawnTransform;
}

FTransform  ATrainingGameMode::GetAISpawnTransform() const {
	return AISpawnTransform;
}

void ATrainingGameMode::SetRLSpawnTransform(const FTransform& Transform) {
	RLSpawnTransform = Transform;
}

void ATrainingGameMode::SetAISpawnTransform(const FTransform& Transform) {
	AISpawnTransform = Transform;
}