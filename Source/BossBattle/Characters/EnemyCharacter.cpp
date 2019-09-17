// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"

#include "Utilities/CustomMacros.h"
#include "Characters/PlayerCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{

	PrimaryActorTick.bCanEverTick = false;
}

void AEnemyCharacter::BeginPlay() {
	Super::BeginPlay();

	bUseControllerRotationYaw = true;

	UCapsuleComponent* ColisionComponent = GetCapsuleComponent();
	if (validate(IsValid(ColisionComponent)) == false) return;
	ColisionComponent->OnComponentHit.AddDynamic(this, &AEnemyCharacter::OnCapsuleHit);

}


void AEnemyCharacter::SetTarget(AActor* TargetToSet) {
	if (validate(IsValid(TargetToSet)) == false) { return; }

	Target = TargetToSet;
}


void AEnemyCharacter::Die() {
	Super::Die();
	
	if (HasAuthority()) {
		AController* EnemyController;
		EnemyController = GetController();
		if (validate(IsValid(EnemyController)) == false) { return; }

		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) { return; }

		EnemyController->StopMovement();
		EnemyController->Destroy();
	}

	SetActorEnableCollision(false);
	UCapsuleComponent* Capsule;
	Capsule = GetCapsuleComponent();
	if (validate(IsValid(Capsule)) == false) { return; }
	Capsule->SetEnableGravity(false);
}

void AEnemyCharacter::OnCapsuleHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (validate(IsValid(OtherActor)) == false) return;
	if (OtherActor->IsA<APlayerCharacter>() == false) return;

	APlayerCharacter* PlayerActor = Cast<APlayerCharacter>(OtherActor);
	if (validate(IsValid(PlayerActor)) == false) return;

	FVector PushBackDirection = -GetActorForwardVector();

	FVector PushBackVelocity = FVector(PushBackDirection.X * PushBackMagnitude, PushBackDirection.Y * PushBackMagnitude, 1);
	LaunchCharacter(PushBackVelocity, false, false);

	UE_LOG(LogTemp, Display, TEXT("Lauching enemy back with force %s"), *PushBackVelocity.ToString())
}
