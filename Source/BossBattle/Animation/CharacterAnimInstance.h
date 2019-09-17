// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "Animation")
class BOSSBATTLE_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	void Die();

	FVector GetRootBonePosition();

	float GetCurrentCoverAnimationTimeRemaining();

	float GetCurrentCoverAnimationTime();

	void SetCoverAimOffsetLimitation(float LowerLimit, float UpperLimit);

	void Reload();

protected:


	void NativeInitializeAnimation() override;

	void NativeUpdateAnimation(float DeltaTimeX) override;

	class ABattleCharacter* CharacterPawn = nullptr;

	class UMovementComponent* MovementComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float AimOffsetVertical;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float AimOffsetHorizontal;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	bool bReload;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float AimingDirection = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float Speed = 0;


private:
	float AimOffsetLowerLimit = -180;

	float AimOffsetUpperLimit = 180;
};
