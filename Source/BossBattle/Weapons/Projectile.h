// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

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

	void SelfDestroy();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent * OverlappedComp,
		AActor * OtherActor, UPrimitiveComponent * OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult & SweepResult);

	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* ArrowComponent = nullptr;


	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UAudioComponent* HitSoundComponent = nullptr;


	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ProjectileDataTable = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FName ProjectileName;

	struct FProjectileData* ProjectileData = nullptr;

	FTimerHandle DestroyTimerHandler;
};
