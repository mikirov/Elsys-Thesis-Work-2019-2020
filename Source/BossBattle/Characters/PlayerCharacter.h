// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BattleCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class BOSSBATTLE_API APlayerCharacter : public ABattleCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UArrowComponent* RotationArrow = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	class USpringArmComponent* SpringArm = nullptr;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	class UCameraComponent* FPCamera = nullptr;
	
	/** third person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	class UCameraComponent* TPCamera = nullptr;

	void OnDeathAnimationEnd() override;

	UFUNCTION()
	void OnHealthChanged(int Health);
	
	void SwapCamera();

	UFUNCTION()
	void PlayCameraShake();
	
	void BeginPlay() override;

	void Die() override;

	UFUNCTION()
	void PickGun(class AGun* NewGun);

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void Restart() override;

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};

