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
#include "Animation/AnimSequence.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundCue.h"

#include "Weapons/Projectile.h"
#include "Weapons/WeaponData.h"
#include "Utilities/CustomMacros.h"
#include "Characters/BattleCharacter.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

void AGun::BeginPlay()
{
	Super::BeginPlay();

	if (validate(IsValid(WeaponDataTable)) == false) return;
	FString ContextString(TEXT("GENERAL"));
	WeaponData = WeaponDataTable->FindRow<FWeaponData>(WeaponName, ContextString);
	if (validate(WeaponData != nullptr) == false) return;

	USoundBase* FireSound = Cast<USoundBase>(WeaponData->FireSound.Get());
	if (IsValid(FireSound)) {
		FireSoundComponent->SetSound(FireSound);
	}
	if (IsValid(GunfireCameraShake.Get())) {
		GunfireCameraShake = WeaponData->CameraShakeTemplate;
	}

	if (WeaponData->bInfiniteAmmo == false) {
		CurrentAmmo = WeaponData->MaxAmmo - WeaponData->MaxClipAmmo;
	}
	else {
		CurrentClipAmmo = WeaponData->MaxClipAmmo;

	}
}

void AGun::PullTrigger() {
	if (validate(WeaponData != nullptr) == false) return;

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
		
		if (IsValid(WeaponData->FireAnimation.Get())) {
			UAnimSequence* FireAnimation = Cast<UAnimSequence>(WeaponData->FireAnimation.Get());

			if (validate(IsValid(FireAnimation)) == false) return;
			SkeletalMeshComponent->PlayAnimation(FireAnimation, false);

		}
		
	}
	else {
		GetWorldTimerManager().ClearTimer(FireTimerHandle);
		StartReload();
	}
}


void AGun::OnDrop()
{
	SetActorRotation(FRotator(0, 0, 0));
	GunState = EGunState::Dropped;
}

void AGun::OnPick()
{
	SetActorRotation(FRotator(0, 0, 0));
	GunState = EGunState::Picked;
}

void AGun::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	switch (GunState)
	{
		case Dropped:
			float ActorRotationYaw = GetActorRotation().Yaw;
			SetActorRotation(FRotator(0, ActorRotationYaw + (RotationPerSecond * deltaTime), 0));
			break;
	}
}

void AGun::SpawnProjectile() {

	if (validate(WeaponData != nullptr) == false) return;
	if (validate(IsValid(ProjectileSpawnTransform)) == false) { return; }

	if (validate(IsValid(WeaponData->ProjectileTemplate.Get())) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	ABattleCharacter* Parent = Cast<ABattleCharacter>(GetAttachParentActor());
	if (validate(IsValid(Parent)) == false) { return; }

	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.Owner = Parent;
	SpawnParameters.Instigator = Parent->Instigator;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

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
	if (IsValid(FireSoundComponent) == false) { return; }

	FireSoundComponent->Play();
}

bool AGun::CanReload()
{
	if (WeaponData->bInfiniteAmmo) {
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

	if (WeaponData->bInfiniteAmmo) {
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



void AGun::SetProjectileSpawnRotationMode(EProjectileSpawnRotation NewSpawnRotation) {
	SpawnRotationMode = NewSpawnRotation;
}


TSubclassOf<UCameraShake> AGun::GetGunfireCameraShake()
{
	return WeaponData->CameraShakeTemplate;
}

bool AGun::IsFiring() {
	return bTriggerPressed;
}