// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Components/AudioComponent.h"
#include "GameFramework/Character.h"
#include "Camera/CameraShake.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/ArrowComponent.h"
#include "ConstructorHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

#include "Weapons/Projectile.h"
#include "Weapons/WeaponData.h"
#include "Utilities/CustomMacros.h"
#include "Characters/BattleCharacter.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	RootComponent = SkeletalMeshComponent;

	FireSoundComponent = CreateDefaultSubobject<UAudioComponent>("FireAudioComponent");
	FireSoundComponent->bAutoActivate = false;
	FireSoundComponent->SetupAttachment(SkeletalMeshComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetupAttachment(SkeletalMeshComponent);
	
	ProjectileSpawnTransform = CreateDefaultSubobject<USceneComponent>("ProjectileSpawnTransform");
	ProjectileSpawnTransform->SetupAttachment(SkeletalMeshComponent);

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
	ArrowComponent->SetupAttachment(ProjectileSpawnTransform);

	ConstructorHelpers::FObjectFinder<UDataTable> WeaponTableAsset(TEXT("DataTable'/Game/TwinStickShooter/Core/Weapons/DT_WeaponStats.DT_WeaponStats'"));
	WeaponDataTable = WeaponTableAsset.Object;
	if (validate(IsValid(WeaponDataTable)) == false) return;

}

void AGun::BeginPlay()
{
	Super::BeginPlay();

	FString ContextString(TEXT("GENERAL"));
	WeaponData = WeaponDataTable->FindRow<FWeaponData>(WeaponName, ContextString);
	if (validate(WeaponData != nullptr) == false) return;

	USoundBase* FireSound = Cast<USoundBase>(WeaponData->FireSound.Get());
	if (validate(IsValid(FireSound))) {
		FireSoundComponent->SetSound(FireSound);
	}
	GunfireCameraShake = WeaponData->CameraShakeTemplate;

	bInfiniteAmmo = WeaponData->bInfiniteAmmo;
	if (bInfiniteAmmo == false) {
		CurrentAmmo = WeaponData->MaxAmmo - WeaponData->MaxClipAmmo;
	}

	CurrentClipAmmo = WeaponData->MaxClipAmmo;
}

void AGun::PullTrigger() {
	GetWorldTimerManager().SetTimer(
		FireTimerHandle,
		this,
		&AGun::Fire,
		1 / WeaponData->FireRate,
		true,
		WeaponData->FireDelay
	);

	bTriggerPressed = true;
}


void AGun::ReleaseTrigger() {
	bTriggerPressed = false;
	GetWorldTimerManager().ClearTimer(FireTimerHandle);
}


void AGun::Fire() {
	if (validate(WeaponData != nullptr) == false) return;
	if (HasAmmo(WeaponData->BulletsPerShot)) {
		PlayFireSound();
		for (int i = 0; i < WeaponData->BulletsPerShot; i++) {
			SpawnProjectile();
		}

	    OnFire.Broadcast();
		CurrentClipAmmo -= WeaponData->BulletsPerShot;
	}
	else {
		GetWorldTimerManager().ClearTimer(FireTimerHandle);
		StartReload();
	}
}


void AGun::SpawnProjectile() {

	if (validate(WeaponData != nullptr) == false) return;
	if (validate(IsValid(ProjectileSpawnTransform)) == false) { return; }

	if (validate(IsValid(WeaponData->ProjectileTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	ABattleCharacter* Parent = Cast<ABattleCharacter>(GetAttachParentActor());
	if (validate(IsValid(Parent)) == false) { return; }

	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.Owner = Parent;
	SpawnParameters.Instigator = Parent->Instigator;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    FRotator ForwardRotator;
	switch (SpawnRotationMode) {
		case EProjectileSpawnRotation::ControlRotation:
			ForwardRotator = Parent->GetControlRotation();
			break;
		case EProjectileSpawnRotation::GunForwardVector:
			ForwardRotator = ProjectileSpawnTransform->GetComponentRotation();
			break;
		default:
			validate(false);
	}

	const int RandomSeed = FMath::Rand();
	FRandomStream RandomStream(RandomSeed);

	FVector ForwardDirection = ForwardRotator.Vector();
	const float ConeHalfAngleRad = FMath::DegreesToRadians(WeaponData->MaxSpreadAngle * 0.5); // we want the half cone angle in radians
	FRotator ShootRotation = RandomStream.VRandCone(ForwardDirection, ConeHalfAngleRad).Rotation();

	FVector SpawnLocation = ProjectileSpawnTransform->GetComponentLocation();



	AProjectile* Projectile = World->SpawnActor<AProjectile>(
		WeaponData->ProjectileTemplate.Get(),
		SpawnLocation,
		ShootRotation,
		SpawnParameters
	);

	validate(IsValid(Projectile));
}


void AGun::PlayFireSound() {
	if (validate(IsValid(FireSoundComponent)) == false) { return; }

	FireSoundComponent->Play();
}

bool AGun::CanReload()
{
	if (bInfiniteAmmo) {
		return true;

	}
	return CurrentAmmo != 0;
}

void AGun::StartReload()
{
	if (CanReload() == false) {
		//play gun blocking animation
		return;
	}
	ABattleCharacter* Character = Cast<ABattleCharacter>(GetAttachParentActor());
	if (validate(IsValid(Character)) == false) return;

	Character->ServerStartReloading();
}

void AGun::FinishReload()
{
	if (validate(WeaponData != nullptr) == false) return;

	if (bInfiniteAmmo) {
		CurrentClipAmmo = WeaponData->MaxClipAmmo;
	}
	else {
		int MissingAmmo = WeaponData->MaxClipAmmo - CurrentClipAmmo;
		int AmmoToTransfer = FMath::Min(MissingAmmo, CurrentAmmo);

		CurrentClipAmmo += AmmoToTransfer;

		CurrentAmmo -= AmmoToTransfer;
	}

	if (bTriggerPressed) {
		PullTrigger();
	}
}



bool AGun::HasAmmo(int Amount)
{
	return CurrentClipAmmo >= Amount;
}

TSubclassOf<UCameraShake> AGun::GetGunfireCameraShake() {
	return GunfireCameraShake;
}


void AGun::SetProjectileSpawnRotationMode(EProjectileSpawnRotation NewSpawnRotation) {
	SpawnRotationMode = NewSpawnRotation;
}


EProjectileSpawnRotation AGun::GetProjectileSpawnRotationMode() {
	return SpawnRotationMode;
}


bool AGun::IsFiring() {
	return bTriggerPressed;
}