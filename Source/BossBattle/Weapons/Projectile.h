// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


//forward declarations
class UProjectileMovementComponent;
class UCapsuleComponent;

UCLASS()
class BOSSBATTLE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent * OverlappedComp,
		AActor * OtherActor, UPrimitiveComponent * OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult & SweepResult);

	UPROPERTY(EditDefaultsOnly)
	UProjectileMovementComponent* ProjectileMovementComponent;
	
	UPROPERTY(BlueprintReadWrite)
	UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Particle")
	UParticleSystem* HitParticleSystem = nullptr;

	//Damage to deal on hit
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float Damage = 30.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	TArray<FName> TagsToIgnore;
};
