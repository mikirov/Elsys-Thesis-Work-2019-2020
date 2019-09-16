// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Sound/SoundBase.h"
#include "WeaponData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bInfiniteAmmo;
	
	// max ammo outside the clip
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MaxAmmo;

	// max clip ammo 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MaxClipAmmo;

	//number of bullets fired per shot
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int BulletsPerShot;

	//max angle the bullets can be spread in.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MaxSpreadAngle;

	//number of times the weapon can fire(per second)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FireRate;

	//delay in seconds that the weapon will wait before firing
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int FireDelay;

	//array of predefined rotations added to the original bullet rotation for every next shot.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRotator> Recoil;

	//camera shake class
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<class UCameraShake> CameraShakeTemplate;
	
	//sound to be played on weapon fire
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<USoundBase> FireSound;

	//type of projectile to use
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<class AProjectile> ProjectileTemplate;


};