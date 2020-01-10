// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDie);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChange, int, Health);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOSSBATTLE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	void TakeDamage(float Damage);

	UFUNCTION()
	void OnRep_HealthCheck();

	void Heal(float HealingPower);

	UFUNCTION(BlueprintCallable)
	float GetHealth();

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth();

	void ResetHealth();

	FDie OnDeath;

	FHealthChange OnHealthChanged;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent) override;
#endif

protected:
	void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly)
	int MaxHealth = 100;

	UPROPERTY(Replicated, ReplicatedUsing = OnRep_HealthCheck, VisibleInstanceOnly)
	float Health;

	bool bDead = false;

	void HealthDamageCheck();

	void HealthHealCheck();
};