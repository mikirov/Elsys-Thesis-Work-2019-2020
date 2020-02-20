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
	
	//self destroy projectile after a given period of time
	void SelfDestroy();

	//event called when the projectile overlaps with another object that has collision enabled
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent * OverlappedComp,
		AActor * OtherActor, UPrimitiveComponent * OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult & SweepResult);

	// arrow indicacting the projectile forward vector visually
	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* ArrowComponent = nullptr;

	// projectile static mesh
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMeshComponent = nullptr;

	//projectile movement component
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent = nullptr;
	
	//capsule indicating projectile hitbox
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CapsuleComponent = nullptr;

	//hit sound component
	UPROPERTY(VisibleAnywhere)
	class UAudioComponent* HitSoundComponent = nullptr;

	//projectile stats data table
	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ProjectileDataTable = nullptr;

	//name of the projectile. Used to find the projectile stats from the datatable
	UPROPERTY(EditDefaultsOnly)
	FName ProjectileName;

	// projectile stats instance
	struct FProjectileData* ProjectileData = nullptr;

	//self destroy timer
	FTimerHandle DestroyTimerHandler;
};
