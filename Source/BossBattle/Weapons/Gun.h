// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UENUM()
enum class EProjectileSpawnRotation : uint8
{
	GunForwardVector, // Less precise but looks better
	ControlRotation // Most precise but doesn't respect actor rotation limits.
};


UCLASS()
class BOSSBATTLE_API AGun : public AActor
{

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFire);

	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	
	UFUNCTION()
	void PullTrigger();

	UFUNCTION()
	void ReleaseTrigger();

	//finishes the weapon reload, updating the ammo
	void FinishReload();


	virtual void BeginPlay() override;

	bool IsFiring();

	void SetProjectileSpawnRotationMode(EProjectileSpawnRotation NewSpawnRotation);

	FFire OnFire;

	TSubclassOf<UCameraShake> GetGunfireCameraShake();

	EProjectileSpawnRotation GetProjectileSpawnRotationMode();

protected:
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USceneComponent* ProjectileSpawnTransform = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UArrowComponent* ArrowComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USphereComponent* SphereComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FName WeaponName;

	class UAudioComponent* FireSoundComponent = nullptr;

	class UDataTable* WeaponDataTable = nullptr;

	bool bTriggerPressed = false;

	UPROPERTY(EditDefaultsOnly, Category = "Gun")
	TSubclassOf<UCameraShake> GunfireCameraShake;

	bool bInfiniteAmmo = false;

	int CurrentAmmo = 0;

	int CurrentClipAmmo = 0;

	EProjectileSpawnRotation SpawnRotationMode = EProjectileSpawnRotation::ControlRotation;

	UFUNCTION()
	void Fire();

	void SpawnProjectile();

	void PlayFireSound();

	FTimerHandle FireTimerHandle;

	bool CanReload();

	//starts the weapon reload, playing the reload animation
	void StartReload();

	bool HasAmmo(int Amount);

private:
	struct FWeaponData* WeaponData = nullptr;
};