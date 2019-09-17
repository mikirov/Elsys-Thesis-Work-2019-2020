// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimNode_StateMachine.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "UnrealNetwork.h"
#include "GameFramework/PlayerState.h"


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

	AimingDirection = (Velocity.Rotation() - CharacterPawn->GetControlRotation()).Yaw;
	AimingDirection = FCustomUtilities::NormalizeFloatAsRotationValue(AimingDirection);

	FRotator RotationDelta = CharacterPawn->GetControlRotation() - CharacterPawn->GetActorRotation();
	RotationDelta = FCustomUtilities::GetStandardUnrealRotation(RotationDelta);

	AimOffsetVertical = RotationDelta.Pitch;
	AimOffsetHorizontal = FMath::Clamp(RotationDelta.Yaw, AimOffsetLowerLimit, AimOffsetUpperLimit);
}


void UCharacterAnimInstance::Die() {
	if (validate(IsValid(CharacterPawn)) == false) return;
	//TODO: play animation
	CharacterPawn->OnDeathAnimationEnd();
	
}

FVector UCharacterAnimInstance::GetRootBonePosition() {
	USkeletalMeshComponent* SkeletalMesh = GetOwningComponent();
	if (validate(IsValid(SkeletalMesh)) == false) { return FVector::ZeroVector; }


	return SkeletalMesh->RootBoneTranslation;
}


float UCharacterAnimInstance::GetCurrentCoverAnimationTimeRemaining() {
	FAnimNode_StateMachine* CoverStateMachine = GetStateMachineInstanceFromName(FName("CoverStateMachine"));
	if (validate(CoverStateMachine != nullptr) == false) { return 0; }


	float TimeRemaining = GetRelevantAnimTimeRemaining(
		GetStateMachineIndex(FName("CoverStateMachine")),
		CoverStateMachine->GetCurrentState()
	);

	return TimeRemaining;
}


float UCharacterAnimInstance::GetCurrentCoverAnimationTime() {
	FAnimNode_StateMachine* CoverStateMachine = GetStateMachineInstanceFromName(FName("CoverStateMachine"));
	if (validate(CoverStateMachine != nullptr) == false) { return 0; }
	

	float Length = GetRelevantAnimLength(
		GetStateMachineIndex(FName("CoverStateMachine")),
		CoverStateMachine->GetCurrentState()
	);

	return Length;
}


void UCharacterAnimInstance::SetCoverAimOffsetLimitation(float LowerLimit, float UpperLimit) {
	AimOffsetLowerLimit = LowerLimit;
	AimOffsetUpperLimit = UpperLimit;
}

void UCharacterAnimInstance::Reload()
{
	//TODO: play reload animation
	CharacterPawn->FinishReloading();
}
