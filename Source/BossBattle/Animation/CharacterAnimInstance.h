// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

UENUM()
enum class EAnimationState : uint8 {
	Walking,
	Dead
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "Animation")
class BOSSBATTLE_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	void Die();

	UFUNCTION(BlueprintImplementableEvent)
	void Reload();

protected:


	void NativeInitializeAnimation() override;

	void NativeUpdateAnimation(float DeltaTimeX) override;

	void OnReloadFinished();

	class ABattleCharacter* CharacterPawn = nullptr;

	class UMovementComponent* MovementComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float AimOffsetVertical;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float AimOffsetHorizontal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bReload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bCrouching = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bInAir = false;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float MovementDirection = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	float Speed = 0;
	
	//UPROPERTY(BlueprintReadOnly, Category = "Animation")
	//float Direction = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Animation")
	EAnimationState AnimationState = EAnimationState::Walking;

	UFUNCTION(BlueprintCallable)
	void OnDeathAnimationEnd();

private:
	float AimOffsetLowerLimit = -180;

	float AimOffsetUpperLimit = 180;
};
