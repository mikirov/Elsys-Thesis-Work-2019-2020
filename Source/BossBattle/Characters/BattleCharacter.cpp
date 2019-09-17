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


	USkeletalMeshComponent* SkeletalMesh = GetMesh();
	if (validate(IsValid(SkeletalMesh)) == false) { return; }
	SkeletalMesh->SetRenderCustomDepth(true);
	
}

// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterMesh = GetMesh();
	if (validate(IsValid(CharacterMesh))) {
		if (validate(IsValid(CharacterAnimationTemplate))) {
			CharacterMesh->SetAnimInstanceClass(CharacterAnimationTemplate);
		}

		CharacterAnimation = Cast<UCharacterAnimInstance>(CharacterMesh->GetAnimInstance());
		validate(IsValid(CharacterAnimation));
	}

	SpawnStartingGun();
	
}

// Called every frame
void ABattleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	if (IsValid(Gun)) {
		Gun->Destroy();
	}
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
		ServerStopFiringRequest();
	}
}

void ABattleCharacter::StartFiringRequest() {
	//bWantsToShoot = true;
	GetWorldTimerManager().SetTimer(
		AttemptFiringTimerHandle,
		this,
		&ABattleCharacter::AttemptFiring,
		0.05,
		true,
		0
	);
}


void ABattleCharacter::StartFiring() {
	Gun->PullTrigger();
}


void ABattleCharacter::StopFiring() {
	Gun->ReleaseTrigger();
}

void ABattleCharacter::InteractWithWeapon()
{
	//drop the current gun if you have one
	if (IsValid(Gun)) {
		DropGun();
	}

	//find gun in a sphere around player with given distance
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	DrawDebugSphere(World, GetActorLocation(), InteractionDistance, 50, FColor::Yellow, false, 1.0f);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	//FIXME
	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery7);
	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery_MAX);

	TArray<AActor*> OverlappedActors;
	TArray<AActor*> ActorsToIgnore;

	UKismetSystemLibrary::SphereOverlapActors(World, GetActorLocation(), InteractionDistance, ObjectTypes, AGun::StaticClass(), ActorsToIgnore, OverlappedActors);
	if (validate(OverlappedActors.Num() != 0) == false) return;


	AGun* NewGun = Cast<AGun>(OverlappedActors[0]);
	if (validate(IsValid(NewGun)) == false) return;

	PickGun(NewGun);
}

void ABattleCharacter::PickGun(class AGun* NewGun)
{
	if (validate(IsValid(NewGun)) == false) { return; }
	if (validate(IsValid(CharacterMesh)) == false) { return; }
	if (validate(CharacterMesh->DoesSocketExist("GunSocket")) == false) { return; }

	Gun = NewGun;
	
	USkeletalMeshComponent* GunMesh = Gun->FindComponentByClass<USkeletalMeshComponent>();
	if (validate(IsValid(GunMesh)) == false) return;

	GunMesh->AttachToComponent(CharacterMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunSocket");
}

void ABattleCharacter::DropGun()
{
	Gun->DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false));
	
	//TODO: set the state of the gun to dropped so that it spins and shines until it gets picked up
	Gun = nullptr;
}

void ABattleCharacter::StopFiringRequest() {

	bWantsToShoot = false;

	IsFiring() ? StopFiring() : GetWorldTimerManager().ClearTimer(AttemptFiringTimerHandle);
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


void ABattleCharacter::AttemptFiring() {
	if (validate(IsValid(Gun)) == false) { return; }
	if (validate(IsFiring() == false) == false) { return; }

	if (bGunCanShoot) {
		StartFiring();
		if (validate(IsFiring())) {
			GetWorldTimerManager().ClearTimer(AttemptFiringTimerHandle);
		}
	}
}

void ABattleCharacter::SpawnStartingGun()
{
	// No validate because player may not have a starting gun.
	if (IsValid(StartingGunTemplate) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.Instigator = Instigator;

	Gun = World->SpawnActor<AGun>(StartingGunTemplate, SpawnInfo);
	PickGun(Gun);
}


void ABattleCharacter::ServerStartFiringRequest_Implementation() {
	StartFiringRequest();
}


bool ABattleCharacter::ServerStartFiringRequest_Validate()
{
	return true;
}

void ABattleCharacter::ServerStopFiringRequest_Implementation() {
	StopFiringRequest();
}


bool ABattleCharacter::ServerStopFiringRequest_Validate()
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