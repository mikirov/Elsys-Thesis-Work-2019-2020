// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Characters/BattleCharacter.h"
#include "Utilities/CustomMacros.h"

#include "UnrealNetwork.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicated(true);
}

#if WITH_EDITOR
void UHealthComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) {
	Super::PostEditChangeProperty(PropertyChangedEvent);
	Health = MaxHealth;
}
#endif

void UHealthComponent::BeginPlay() {
	Super::BeginPlay();

	validate(MaxHealth > 0);
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, Health);
}


void UHealthComponent::TakeDamage(float Damage) {
	if (bDead) { return; }

	Health -= Damage;
	HealthDamageCheck();
	
	OnHealthChanged.Broadcast(Health);
}


void UHealthComponent::HealthDamageCheck() {
	if (Health <= 0) {
		bDead = true;
		OnDeath.Broadcast();
	}
}


void UHealthComponent::Heal(float HealingPower) {
	if (bDead) { return; }

	Health += HealingPower;
	HealthHealCheck();

	OnHealthChanged.Broadcast(Health);
}


void UHealthComponent::HealthHealCheck() {
	if (Health > MaxHealth) {
		Health = MaxHealth;
	}
}


void UHealthComponent::OnRep_HealthCheck() {
	if (bDead) { return; }

	HealthDamageCheck();
	HealthHealCheck();

	OnHealthChanged.Broadcast(Health);
}


float UHealthComponent::GetHealth() {
	return Health;
}

float UHealthComponent::GetMaxHealth() {
	return MaxHealth;
}
