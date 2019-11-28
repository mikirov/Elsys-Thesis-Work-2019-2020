// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Components/ArrowComponent.h"
#include "ConstructorHelpers.h"
#include "TimerManager.h"

#include "Weapons/ProjectileData.h"
#include "Characters/BattleCharacter.h"
#include "Characters/HealthComponent.h"
#include "Utilities/CustomMacros.h"


AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	SetRootComponent(ArrowComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(ArrowComponent);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetupAttachment(ArrowComponent);

	HitSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("HitSoundComponent"));
	HitSoundComponent->SetupAttachment(ArrowComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->ProjectileGravityScale = 0;
	ProjectileMovementComponent->bAutoActivate = true;

	bReplicates = true;

	this->Tags.Add(FName("Projectile"));

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	if (validate(IsValid(ProjectileDataTable)) == false) return;
	FString ContextString(TEXT("GENERAL"));
	ProjectileData = ProjectileDataTable->FindRow<FProjectileData>(ProjectileName, ContextString);
	if (validate(ProjectileData != nullptr) == false) return;

	AActor* DamageDealer;
	if (validate(IsValid(CapsuleComponent))) { 
		DamageDealer = GetOwner();
		if (validate(IsValid(DamageDealer)) == false) { return; }

		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::AProjectile::OnOverlapBegin);
		CapsuleComponent->IgnoreActorWhenMoving(DamageDealer, true);
	}
	GetWorldTimerManager().SetTimer(
		DestroyTimerHandler,
		this,
		&AProjectile::SelfDestroy,
		-1.0f,
		false,
		ProjectileData->SelfDestroyTime);
}

//wrapper to pass as function pointer compatible with timers
void AProjectile::SelfDestroy()
{
	Destroy();
}

void AProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor == this) return;
	for (FName Tag : OtherActor->Tags) {
		if (ProjectileData->TagsToIgnore.Contains(Tag)) {
			return;
		}
	}


	if (HasAuthority()) {
		if (validate(IsValid(OtherActor)) == false) { return; }

		UHealthComponent* HealthComponent = OtherActor->FindComponentByClass<UHealthComponent>();
		if (IsValid(HealthComponent)) {
			HealthComponent->TakeDamage(ProjectileData->Damage);
		}
	}

	if (IsValid(ProjectileData->HitParticleSystem)) {
		UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			ProjectileData->HitParticleSystem,
			GetActorTransform()
		);
	}
	if (IsValid(HitSoundComponent)) {
		USoundBase* Sound = nullptr;
		if (OtherActor->IsA<ABattleCharacter>() && IsValid(ProjectileData->HitEnemySound.Get())) {
			Sound = Cast<USoundBase>(ProjectileData->HitEnemySound.Get());
		}
		else {
			Sound = Cast<USoundBase>(ProjectileData->HitGroundSound.Get());
		}
		if (IsValid(Sound)) {
			HitSoundComponent->SetSound(Sound);
			HitSoundComponent->Play();
		}

	}
	Destroy();
}

