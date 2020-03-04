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


	void SetChat(class UChatWidget* ChatWidget);

	AGun* GetGun();

protected:


	UFUNCTION()
	void OnHealthChanged(float Value);

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

	/** third person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
	class UCameraComponent* TPCamera = nullptr;

	//healthbar widget
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UWidgetComponent* WidgetComponent = nullptr;

	void OnDeathAnimationEnd() override;

	class UChatWidget* ChatWidget = nullptr;

	UFUNCTION()
	void OpenChat();

	//quit current level
	UFUNCTION()
	void Close();

	//UFUNCTION()
	//void OnHealthChanged(int Health);

	UFUNCTION()
	void PlayCameraShake();
	
	void BeginPlay() override;

	void Die() override;

	UFUNCTION()
	void PickGun(class AGun* NewGun);

	UFUNCTION()
	void HandleCrouch();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

