// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"

#include "Gamemodes/BossBattleGameMode.h"
#include "Utilities/CustomMacros.h"
#include "Characters/PlayerCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}




void AEnemyCharacter::SetTarget(AActor* TargetToSet) {
	if (validate(IsValid(TargetToSet)) == false) { return; }

	Target = TargetToSet;
}


void AEnemyCharacter::Die() {
	Super::Die();
	
	if (HasAuthority()) {
		AController* EnemyController;
		EnemyController = GetController();
		if (validate(IsValid(EnemyController)) == false) { return; }

		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }

		EnemyController->StopMovement();
		EnemyController->Destroy();

		ABossBattleGameMode* GameMode = Cast<ABossBattleGameMode>(World->GetAuthGameMode());
		if (validate(IsValid(GameMode)) == false) { return; }

		GameMode->IncrementScore(Score);
		GameMode->DecrementEnemyCounter();
	}

	SetActorEnableCollision(false);
	UCapsuleComponent* Capsule;
	Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule)) == false) { return; }
	Capsule->SetEnableGravity(false);
}
