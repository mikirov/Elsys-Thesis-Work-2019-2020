// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BattleCharacter.generated.h"

UCLASS(config = Game)
class BOSSBATTLE_API ABattleCharacter : public ACharacter
{
	GENERATED_BODY()

public:


	// Sets default values for this character's properties
	ABattleCharacter();

	// Checks whether firing is possible
	bool IsFiring();

	//might not be needed
	void Move(FVector Direction);

	FRotator GetAimAtRotation(FVector TargetLocation);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartFiring();
	bool ServerStartFiring_Validate();
	void ServerStartFiring_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStopFiring();
	bool ServerStopFiring_Validate();
	void ServerStopFiring_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartReloading();
	bool ServerStartReloading_Validate();
	void ServerStartReloading_Implementation();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerFinishReloading();
	bool ServerFinishReloading_Validate();
	void ServerFinishReloading_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerInteractWithWeapon();
	bool ServerInteractWithWeapon_Validate();
	void ServerInteractWithWeapon_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartCrouching();
	bool ServerStartCrouching_Validate();
	void ServerStartCrouching_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStopCrouching();
	bool ServerStopCrouching_Validate();
	void ServerStopCrouching_Implementation();



	virtual void OnDeathAnimationEnd();

	void FinishReloading();

	void StartFiring();

	void StopFiring();

	bool IsDead();
	
	UFUNCTION()
	void StartCrouch();

	UFUNCTION()
	void EndCrouch();


	class UHealthComponent* GetHealthComponent();

	bool IsCrouching();

protected:

	bool bCrouching = false;

	UPROPERTY(EditDefaultsOnly, Category = "Gun")
	TSubclassOf<class AGun> StartingGunTemplate = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Gun")
	class AGun* Gun = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Base Character")
	class USkeletalMeshComponent* CharacterMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Base Character")
	class UHealthComponent* HealthComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Base Character")
	class UAudioComponent* DeathSoundComponent = nullptr;

	class UCharacterAnimInstance* CharacterAnimation = nullptr;

	class UCharacterMovementComponent* CharacterMovementComponent = nullptr;

	bool bGunCanShoot = false;
	
	UFUNCTION()
	virtual void Die();

	void Destroyed() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InteractWithWeapon();

	void PickGun(class AGun* NewGun);

	void DropGun();
	
	float InteractionDistance = 100.0f;

	// In process of reloading
	bool bReloading = false;

	bool bReloadingAllowed = true;

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastStartReloading();
	bool MulticastStartReloading_Validate();
	void MulticastStartReloading_Implementation();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastStartCrouching();
	bool MulticastStartCrouching_Validate();
	void MulticastStartCrouching_Implementation();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastStopCrouching();
	bool MulticastStopCrouching_Validate();
	void MulticastStopCrouching_Implementation();


	void StartReloading();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastFinishReloading();
	bool MulticastFinishReloading_Validate();
	void MulticastFinishReloading_Implementation();

	UFUNCTION()
	void UpdateGun();

	FTimerHandle AttemptFiringTimerHandle;

	void SpawnStartingGun();



private:

	bool bDead = false;
};
