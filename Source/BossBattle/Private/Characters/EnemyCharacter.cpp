// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "Characters/HealthComponent.h"
#include "Gamemodes/BossBattleGameMode.h"
#include "Utilities/CustomMacros.h"


#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "UI/BattleHUD.h"
#include "Characters/PlayerCharacterController.h"
#include "UI/PlayerStatsWidget.h"

#include "TimerManager.h"



void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();


	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) {
		APlayerCharacterController* PlayerCharacterController = Cast<APlayerCharacterController>(*Iterator);
		if (IsValid(Controller) == false) return;

		ABattleHUD* HUD = Cast<ABattleHUD>(PlayerCharacterController->GetHUD());
		if (validate(IsValid(HUD)) == false) return;

		UPlayerStatsWidget* PlayerStatsWidget = HUD->GetPlayerStatsWidget();
		if (validate(IsValid(PlayerStatsWidget)) == false) return;

		float Percent = 1.0f;
		PlayerStatsWidget->SetEnemyHealth(Percent);
	}
}


void AEnemyCharacter::Die()
{
	UE_LOG(LogTemp, Warning, TEXT("AEnemyCharacter::Die()"))
	Super::Die();

	if (HasAuthority()) {
		AController* EnemyController;
		EnemyController = GetController();
		if (validate(IsValid(EnemyController)) == false) { return; }

		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }

		EnemyController->StopMovement();
		EnemyController->Destroy();

		SetDead(true);
		ServerStopFiring();

		ABossBattleGameMode* BossBattleGameMode = Cast<ABossBattleGameMode>(World->GetAuthGameMode());
		if (IsValid(BossBattleGameMode)) {
			BossBattleGameMode->IncrementScore(Score);

			BossBattleGameMode->DecrementEnemyCounter();
			return;
		}
		
	}

	SetActorEnableCollision(false);
	UCapsuleComponent* Capsule;
	Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule)) == false) { return; }
	Capsule->SetEnableGravity(false);
}



void AEnemyCharacter::OnTakingDamage(float CurrentHealth)
{
	Super::OnTakingDamage(CurrentHealth);

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) {
		APlayerCharacterController* PlayerCharacterController = Cast<APlayerCharacterController>(*Iterator);
		if (validate(IsValid(PlayerCharacterController)) == false) return;
		
		ABattleHUD* HUD = Cast<ABattleHUD>(PlayerCharacterController->GetHUD());
		if (validate(IsValid(HUD)) == false) return;

		UPlayerStatsWidget* PlayerStatsWidget = HUD->GetPlayerStatsWidget();
		if (validate(IsValid(PlayerStatsWidget)) == false) return;

		float Percent = CurrentHealth / HealthComponent->GetMaxHealth();
		PlayerStatsWidget->SetEnemyHealth(Percent);
	}

}
