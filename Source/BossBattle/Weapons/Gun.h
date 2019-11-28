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
	

	//sets a timer to fire at given interval
	UFUNCTION()
	void PullTrigger();

	//resets the firing timer
	UFUNCTION()
	void ReleaseTrigger();

	//finishes the weapon reload, updating the ammo
	void FinishReload();

	virtual void BeginPlay() override;


	//checks whheter or not the weapon is firing
	bool IsFiring();

	//setter for the projectile initial rotation mode
	void SetProjectileSpawnRotationMode(EProjectileSpawnRotation NewSpawnRotation);

	//event emitted on fire
	FFire OnFire;

	//getter for camera shake on fire
	TSubclassOf<class UCameraShake> GetGunfireCameraShake();

	//event on weapon dropped
	void OnDrop();

	//event on weapon picked
	void OnPick();
protected:
	
	//the initial transform of the projectile
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* ProjectileSpawnTransform = nullptr;

	//the skeletal mesh of the weapon
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USkeletalMeshComponent* SkeletalMeshComponent = nullptr;

	//arrow pointing in the shooting direction
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UArrowComponent* ArrowComponent = nullptr;

	//weapon pickup collision sphere
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* SphereComponent = nullptr;

	//the name of the weapon, used in the data table
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FName WeaponName;

	//sound emitter
	class UAudioComponent* SoundComponent = nullptr;

	//data table with weapon stats
	UPROPERTY(EditDefaultsOnly)
	class UDataTable* WeaponDataTable = nullptr;

	//camera shake played on fire
	UPROPERTY(EditDefaultsOnly, Category = "Gun")
	TSubclassOf<class UCameraShake> GunfireCameraShake;

	//whether or not the fire trigger is pressed
	bool bTriggerPressed = false;

	//total current weapon ammunition
	int CurrentAmmo = 0;

	//current weapon ammunitions in this clip
	int CurrentClipAmmo = 0;

	//specifies how the projectile will get its initial rotation
	EProjectileSpawnRotation SpawnRotationMode = EProjectileSpawnRotation::ControlRotation;

	//degrees to rotate around yaw axis while dropped
	float RotationPerSecond = 45.0f;

	//spawns a projectile and specifies initial projectile parameters
	UFUNCTION()
	void Fire();

	virtual void Tick(float deltaTime);

	//spawns the projectile
	void SpawnProjectile();

	//at location
	void PlayFireSound();

	//timer for fire events
	FTimerHandle FireTimerHandle;

	//whether the gun can reload or not
	bool CanReload();

	//starts the weapon reload, playing the reload animation
	void StartReload();

	//whether or not we have enough ammunitions to shoot
	bool HasAmmo(int Amount);

	//current gun state
	enum EGunState GunState = EGunState::Dropped;

	//weapon data struct, containing all of the guns attributes
	struct FWeaponData* WeaponData = nullptr;
};