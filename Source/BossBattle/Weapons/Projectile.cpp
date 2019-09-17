// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Characters/HealthComponent.h"
#include "Utilities/CustomMacros.h"

AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile movement component"));
	ProjectileMovementComponent->ProjectileGravityScale = 0;

	bReplicates = true;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	AActor* DamageDealer;
	if (validate(IsValid(CapsuleComponent))) { 
		DamageDealer = GetOwner();
		if (validate(IsValid(DamageDealer)) == false) { return; }

		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::AProjectile::OnOverlapBegin);
		CapsuleComponent->IgnoreActorWhenMoving(DamageDealer, true);
	}

	validate(IsValid(HitParticleSystem));
	validate(TagsToIgnore.Num() > 0);
}

void AProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (validate(IsValid(OtherActor)) == false) { return; }

	for (FName Tag : OtherActor->Tags) {
		if (TagsToIgnore.Contains(Tag)) {
			return;
		}
	}

	if (HasAuthority()) {
		UHealthComponent* HealthComponent = OtherActor->FindComponentByClass<UHealthComponent>();
		if (IsValid(HealthComponent)) {
			HealthComponent->TakeDamage(Damage);
		}
	}

	if (validate(IsValid(HitParticleSystem))) {
		UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			HitParticleSystem,
			GetActorTransform()
		);
	}

	Destroy();
}

