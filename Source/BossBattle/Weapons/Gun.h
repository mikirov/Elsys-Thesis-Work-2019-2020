// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

enum EProjectileSpawnRotation : uint8
{
	GunForwardVector, // Less precise but looks better
	ControlRotation // Most precise but doesn't respect actor rotation limits.
};

enum EGunState
{
	Picked,
	Dropped
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

	TSubclassOf<class UCameraShake> GetGunfireCameraShake();

	void OnDrop();

	void OnPick();
protected:
	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* ProjectileSpawnTransform = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UArrowComponent* ArrowComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* SphereComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FName WeaponName;

	class UAudioComponent* FireSoundComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UDataTable* WeaponDataTable = nullptr;

	bool bTriggerPressed = false;

	UPROPERTY(EditDefaultsOnly, Category = "Gun")
	TSubclassOf<class UCameraShake> GunfireCameraShake;

	int CurrentAmmo = 0;

	int CurrentClipAmmo = 0;

	EProjectileSpawnRotation SpawnRotationMode = EProjectileSpawnRotation::ControlRotation;

	//degrees to rotate around yaw axis while dropped
	float RotationPerSecond = 45.0f;

	UFUNCTION()
	void Fire();

	virtual void Tick(float deltaTime);

	void SpawnProjectile();

	void PlayFireSound();

	FTimerHandle FireTimerHandle;

	bool CanReload();

	//starts the weapon reload, playing the reload animation
	void StartReload();

	bool HasAmmo(int Amount);

	enum EGunState GunState = EGunState::Dropped;

	struct FWeaponData* WeaponData = nullptr;
};