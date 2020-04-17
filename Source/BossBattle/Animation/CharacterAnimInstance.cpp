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

#include "Animation/AnimMontage.h"
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
	MovementDirection = CalculateDirection(Velocity, CharacterPawn->GetControlRotation());
	UPawnMovementComponent* CharacterMovement = CharacterPawn->GetMovementComponent();
	if (validate(IsValid(CharacterMovement)) == false) return;
	bInAir = CharacterMovement->IsFalling();
}


void UCharacterAnimInstance::OnReloadFinished()
{
	if (validate(AnimationState != EAnimationState::Dead) == false) return;

	UE_LOG(LogTemp, Warning, TEXT("UCharacterAnimInstance::OnReloadFinished"))
	CharacterPawn->ServerFinishReloading();
}

void UCharacterAnimInstance::OnDeathAnimationEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAnimInstance::OnDeathAnimationEnd"))
	if (validate(IsValid(CharacterPawn)) == false) return;
	CharacterPawn->OnDeathAnimationEnd();

}

void UCharacterAnimInstance::Die() {
	UE_LOG(LogTemp, Warning, TEXT("UCharacterAnimInstance::Die"))
	AnimationState = EAnimationState::Dead;
	
}


void UCharacterAnimInstance::SetCrouching(bool State)
{
	if (AnimationState == EAnimationState::Dead) return;

	UE_LOG(LogTemp, Warning, TEXT("UCharacterAnimInstance::SetCrouching"))
	bCrouching = State;
}

void UCharacterAnimInstance::SetReloading(bool State) {
	if (validate(AnimationState != EAnimationState::Dead) == false) return;

	if (State) {
		PreviousState = AnimationState;
		AnimationState = EAnimationState::Reloading;
		UE_LOG(LogTemp, Warning, TEXT(" UCharacterAnimInstance::SetReloading(true)"))
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT(" UCharacterAnimInstance::SetReloading(false)"))
		AnimationState = PreviousState;
	}
}

