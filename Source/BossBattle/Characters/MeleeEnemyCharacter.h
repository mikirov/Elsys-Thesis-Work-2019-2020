// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/EnemyCharacter.h"
#include "MeleeEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AMeleeEnemyCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
public:
	AMeleeEnemyCharacter();

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DamageBox = nullptr;

	//Box component overlap begin overlap event
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	//Box component overlap end overlap event
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	void DealDamage();

	//Rate at which the ai controller deals damage (in seconds)
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DamageRate = 1.0f;

	//Delay before starting to deal damage (in seconds)
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DamageDelay = 0.1f;

	//Damage to deal to the player, per hit
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DamagePerHit = 30.0f;

	FTimerHandle DamageTimerHandle;
};
