// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleCharacter.h"
#include "GameFramework/Controller.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/AudioComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "UnrealNetwork.h"
#include "Kismet/KismetSystemLibrary.h"


#include "Animation/CharacterAnimInstance.h"
#include "Characters/HealthComponent.h"
#include "Weapons/Gun.h"
#include "Utilities/CustomMacros.h"


// Sets default values
ABattleCharacter::ABattleCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DeathSoundComponent = CreateDefaultSubobject<UAudioComponent>("DeathSoundAudioComponent");
	DeathSoundComponent->bAutoActivate = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	HealthComponent->OnDeath.AddDynamic(this, &ABattleCharacter::Die);
	HealthComponent->SetIsReplicated(true);

	CharacterMovementComponent = Cast<UCharacterMovementComponent>(GetCharacterMovement());
	if (validate(IsValid(CharacterMovementComponent)) == false) return;
	CharacterMovementComponent->GetNavAgentPropertiesRef().bCanCrouch = true;
	CharacterMovementComponent->bCrouchMaintainsBaseLocation = true;
	CharacterMovementComponent->SetIsReplicated(true);


	USkeletalMeshComponent* SkeletalMesh = GetMesh();
	if (validate(IsValid(SkeletalMesh)) == false) { return; }
	
}

// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterMesh = GetMesh();
	if (validate(IsValid(CharacterMesh)) == false) return;

	CharacterAnimation = Cast<UCharacterAnimInstance>(CharacterMesh->GetAnimInstance());
	validate(IsValid(CharacterAnimation));

	SpawnStartingGun();
	
}


bool ABattleCharacter::IsFiring()
{
	if (validate(IsValid(Gun)) == false) { return false; }
	return Gun->IsFiring();
}

void ABattleCharacter::Move(FVector Direction) {
	AddMovementInput(Direction);
}

FRotator ABattleCharacter::GetAimAtRotation(FVector TargetLocation) {
	
	if (validate(IsValid(Gun)) == false) { return FRotator(0, 0, 0); }

	FVector StartLocation = GetActorLocation();
	StartLocation.Z = Gun->GetActorLocation().Z;

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		StartLocation,
		TargetLocation
	);

	return LookAtRotation;

}


void ABattleCharacter::OnDeathAnimationEnd()
{
	Destroy();
}

void ABattleCharacter::Die()
{
	
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	if (validate(IsValid(DeathSoundComponent))) {
		DeathSoundComponent->Play();
	}

	if (validate(IsValid(CharacterAnimation))) {
		CharacterAnimation->Die();
	}
	
	
	if (IsFiring()) {
		ServerStopFiring();
	}
}

void ABattleCharacter::Destroyed()
{
	Super::Destroyed();

	if (IsValid(Gun)) {
		Gun->Destroy();
	}
}

void ABattleCharacter::StartFiring() {
	if (validate(IsValid(Gun)) == false) return;
	Gun->PullTrigger();
}


void ABattleCharacter::StopFiring() {
	if (validate(IsValid(Gun)) == false) return;

	Gun->ReleaseTrigger();
}

class UHealthComponent* ABattleCharacter::GetHealthComponent()
{
	return HealthComponent;
}

void ABattleCharacter::InteractWithWeapon()
{
	AGun* OldGun = nullptr;
	if (IsValid(Gun)) {
		OldGun = Gun;
	}
	//drop the current gun if you have one
	if (IsValid(Gun)) {
		DropGun();
	}

	//find gun in a sphere around player with given distance
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	DrawDebugSphere(World, GetActorLocation(), InteractionDistance, 50, FColor::Yellow, false, 1.0f);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery7);

	TArray<AActor*> OverlappedActors;
	TArray<AActor*> ActorsToIgnore;

	UKismetSystemLibrary::SphereOverlapActors(World, GetActorLocation(), InteractionDistance, ObjectTypes, AGun::StaticClass(), ActorsToIgnore, OverlappedActors);
	if (validate(OverlappedActors.Num() != 0) == false) return;
	for (auto OverlappedActor : OverlappedActors) {
		
		AGun* NewGun = Cast<AGun>(OverlappedActor);
		if (validate(IsValid(NewGun)) == false) continue;
		if (NewGun == OldGun) continue;

		PickGun(NewGun);
		break;
	}

}

void ABattleCharacter::PickGun(class AGun* NewGun)
{
	if (HasAuthority() == false) return;

	if (validate(IsValid(NewGun)) == false) { return; }
	if (validate(IsValid(CharacterMesh)) == false) { return; }
	if (validate(CharacterMesh->DoesSocketExist("GunSocket")) == false) { return; }

	Gun = NewGun;
	
	USkeletalMeshComponent* GunMesh = Gun->FindComponentByClass<USkeletalMeshComponent>();
	if (validate(IsValid(GunMesh)) == false) return;


	Gun->OnPick();

	GunMesh->AttachToComponent(CharacterMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunSocket");
}

void ABattleCharacter::DropGun()
{
	if (HasAuthority() == false) return;


	if (validate(IsValid(Gun)) == false) return;

	Gun->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false));

	Gun->OnDrop();
	
	Gun = nullptr;
}

void ABattleCharacter::StartReloading()
{
	if (bReloadingAllowed == false) { return; }
	if (validate(IsValid(Gun)) == false) { return; }

	bReloadingAllowed = false;
	CharacterAnimation->Reload();
}

void ABattleCharacter::FinishReloading()
{
	if (validate(IsValid(Gun)) == false) return;

	bReloadingAllowed = true;
	Gun->FinishReload();
}


void ABattleCharacter::SpawnStartingGun()
{
	if (HasAuthority() == false) return;

	// No validate because player may not have a starting gun.
	if (IsValid(StartingGunTemplate.Get()) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.Instigator = GetInstigator();

	Gun = World->SpawnActor<AGun>(StartingGunTemplate, SpawnInfo);
	PickGun(Gun);
}


void ABattleCharacter::ServerStartFiring_Implementation() {
	StartFiring();
}


bool ABattleCharacter::ServerStartFiring_Validate()
{
	return true;
}

void ABattleCharacter::ServerStopFiring_Implementation() {
	StopFiring();
}


bool ABattleCharacter::ServerStopFiring_Validate()
{
	return true;
}

void ABattleCharacter::ServerStartReloading_Implementation()
{
	MulticastStartReloading();
}

bool ABattleCharacter::ServerStartReloading_Validate()
{
	return true;
}

void ABattleCharacter::ServerFinishReloading_Implementation()
{
	MulticastFinishReloading();
}

bool ABattleCharacter::ServerFinishReloading_Validate()
{
	return true;
}

void ABattleCharacter::MulticastStartReloading_Implementation()
{
	StartReloading();
}

bool ABattleCharacter::MulticastStartReloading_Validate() {
	return true;
}


void ABattleCharacter::MulticastFinishReloading_Implementation()
{
	FinishReloading();
}

bool ABattleCharacter::MulticastFinishReloading_Validate()
{
	return true;
}

void ABattleCharacter::ServerInteractWithWeapon_Implementation()
{
	InteractWithWeapon();
}


bool ABattleCharacter::ServerInteractWithWeapon_Validate()
{
	return true;
}