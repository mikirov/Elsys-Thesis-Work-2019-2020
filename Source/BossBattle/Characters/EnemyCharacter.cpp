// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "Characters/HealthComponent.h"
#include "Gamemodes/BossBattleGameMode.h"
#include "Utilities/CustomMacros.h"


#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

void AEnemyCharacter::Reset() {
	
	HealthComponent->ResetHealth();

	bDead = false;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	HealthComponent->OnHealthChanged.AddDynamic(this, &AEnemyCharacter::OnTakingDamage);
}

bool AEnemyCharacter::IsTakingDamage()
{
	return bTakingDamage;
}

bool AEnemyCharacter::IsDead()
{
	return bDead;
}

bool AEnemyCharacter::IsOnCriticalHealth()
{
	return bCriticalHealth;
}

void AEnemyCharacter::Die()
{
	Super::Die();

	if (HasAuthority()) {
		//TODO: destroy only when we don't reset
		AController* EnemyController;
		EnemyController = GetController();
		if (validate(IsValid(EnemyController)) == false) { return; }

		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }

		EnemyController->StopMovement();
		EnemyController->Destroy();

		bDead = true;
		ServerStopFiring();

		ABossBattleGameMode* BossBattleGameMode = Cast<ABossBattleGameMode>(World->GetAuthGameMode());
		if (IsValid(BossBattleGameMode)) {
			BossBattleGameMode->IncrementScore(Score);
			//BossBattleGameMode->DecrementEnemyCounter();
			return;
		}
		
	}

	SetActorEnableCollision(false);
	UCapsuleComponent* Capsule;
	Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule)) == false) { return; }
	Capsule->SetEnableGravity(false);
}

void AEnemyCharacter::ClearTakingDamage() {
	bTakingDamage = false;
}

void AEnemyCharacter::OnTakingDamage(float CurrentHealth)
{
	bTakingDamage = true;
	bCriticalHealth = (CurrentHealth < HealthComponent->GetMaxHealth() / 3);


	//TODO: make sure bDead is actually working as expected

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemyCharacter::ClearTakingDamage, 0.0f, false, 0.25f);

}
