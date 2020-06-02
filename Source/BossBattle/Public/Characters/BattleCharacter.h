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
	UFUNCTION(BlueprintCallable)
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

	UFUNCTION(Server, Reliable, WithValidation)
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


	UFUNCTION(BlueprintCallable)
	void StartFiring();


	UFUNCTION(BlueprintCallable)
	void StopFiring();

	bool IsDead();
	

	UFUNCTION(BlueprintCallable)
	void StartCrouch();


	UFUNCTION(BlueprintCallable)
	void EndCrouch();


	class UHealthComponent* GetHealthComponent();

	UFUNCTION(BlueprintCallable)
	bool IsCrouching();

	bool IsDead() const { return bDead; }
	void SetDead(bool val) { bDead = val; }
	bool IsTakingDamage() const { return bTakingDamage; }
	void SetTakingDamage(bool val) { bTakingDamage = val; }
	bool IsCriticalHealth() const { return bCriticalHealth; }
	void SetCriticalHealth(bool val) { bCriticalHealth = val; }

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

	UFUNCTION(BlueprintCallable)
	bool InteractWithWeapon();

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

	UFUNCTION(BlueprintCallable)
	bool StartReloading();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastFinishReloading();
	bool MulticastFinishReloading_Validate();
	void MulticastFinishReloading_Implementation();

	UFUNCTION()
	virtual void OnTakingDamage(float Amount);

	UFUNCTION()
	void ClearTakingDamage();

	UFUNCTION()
	void UpdateGun();

	FTimerHandle AttemptFiringTimerHandle;

	void SpawnStartingGun();

	// Is the character dead?
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Enemy Character")
	bool bDead = false;

	// Is the character taking damage?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Character")
	bool bTakingDamage = false;

	// Is the character on critical health ?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Character")
	bool bCriticalHealth = false;


};
