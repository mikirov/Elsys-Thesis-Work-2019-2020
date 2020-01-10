// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimNode_StateMachine.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "UnrealNetwork.h"
#include "GameFramework/PlayerState.h"
#include "TimerManager.h"
#include "Engine/World.h"

#include "Characters/BattleCharacter.h"
#include "Utilities/CustomMacros.h"
#include "Utilities/CustomUtilities.h"

void UCharacterAnimInstance::NativeInitializeAnimation() {
	Super::NativeInitializeAnimation();

	CharacterPawn = Cast<ABattleCharacter>(TryGetPawnOwner());
	if (validate(IsValid(CharacterPawn)) == false) { return; }
}


void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaTimeX) {
	Super::NativeUpdateAnimation(DeltaTimeX);

	if (validate(IsValid(CharacterPawn)) == false) { return; }

	FVector Velocity = CharacterPawn->GetVelocity();
	Speed = Velocity.Size();

	//MovementDirection = CalculateDirection(Velocity, CharacterPawn->GetControlRotation());


	//AimingDirection = (Velocity.Rotation() - CharacterPawn->GetControlRotation()).Yaw;
	//AimingDirection = FCustomUtilities::NormalizeFloatAsRotationValue(AimingDirection);
	//
	//MovementDirection = (Velocity.Rotation() - CharacterPawn->GetControlRotation()).Yaw;
	//MovementDirection = FCustomUtilities::NormalizeFloatAsRotationValue(MovementDirection);
	//
	UPawnMovementComponent* CharacterMovement = CharacterPawn->GetMovementComponent();
	if (validate(IsValid(CharacterMovement)) == false) return;
	bCrouching = CharacterMovement->IsCrouching();
	bInAir = CharacterMovement->IsFalling();

	//FRotator RotationDelta = CharacterPawn->GetControlRotation() - CharacterPawn->GetActorRotation();
	//RotationDelta = FCustomUtilities::GetStandardUnrealRotation(RotationDelta);

	//AimOffsetVertical = RotationDelta.Pitch;
	//AimOffsetHorizontal = FMath::Clamp(RotationDelta.Yaw, AimOffsetLowerLimit, AimOffsetUpperLimit);
}


void UCharacterAnimInstance::OnReloadFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAnimInstance::OnReloadFinished"))
	CharacterPawn->ServerFinishReloading();
}

void UCharacterAnimInstance::OnDeathAnimationEnd()
{
	if (validate(IsValid(CharacterPawn)) == false) return;
	CharacterPawn->OnDeathAnimationEnd();

}

void UCharacterAnimInstance::Die() {
	AnimationState = EAnimationState::Dead;
	
}

