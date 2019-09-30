// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeEnemyCharacter.h"

#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

#include "Characters/PlayerCharacter.h"
#include "Characters/HealthComponent.h"
#include "Utilities/CustomMacros.h"


AMeleeEnemyCharacter::AMeleeEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMeleeEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (validate(IsValid(DamageBox))) {
		DamageBox->OnComponentBeginOverlap.AddDynamic(this, &AMeleeEnemyCharacter::OnBoxBeginOverlap);
		DamageBox->OnComponentEndOverlap.AddDynamic(this, &AMeleeEnemyCharacter::OnOverlapEnd);
	}
}

void AMeleeEnemyCharacter::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (validate(IsValid(OtherActor)) == false) { return; }

	if (OtherActor->IsA<APlayerCharacter>()) {
		Target = OtherActor;

		GetWorldTimerManager().SetTimer(
			DamageTimerHandle,
			this,
			&AMeleeEnemyCharacter::DealDamage,
			DamageRate,
			true,
			DamageDelay
		);
	}

}

void AMeleeEnemyCharacter::DealDamage()
{
	if (validate(IsValid(Target)) == false) { return; }

	HealthComponent = Target->FindComponentByClass<UHealthComponent>();
	if (validate(IsValid(HealthComponent))) {
		HealthComponent->TakeDamage(DamagePerHit);
	}
}

void AMeleeEnemyCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (validate(IsValid(Target)) == false) { return; }

	if (OtherActor == Target) {
		GetWorldTimerManager().ClearTimer(DamageTimerHandle);
	}
}
