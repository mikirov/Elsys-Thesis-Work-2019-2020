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

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Checks whether firing is possible
	bool IsFiring();

	void Destroyed() override;

	//might not be needed
	void Move(FVector Direction);

	FRotator GetAimAtRotation(FVector TargetLocation);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartFiringRequest();
	bool ServerStartFiringRequest_Validate();
	void ServerStartFiringRequest_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStopFiringRequest();
	bool ServerStopFiringRequest_Validate();
	void ServerStopFiringRequest_Implementation();

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

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Gun")
	TSubclassOf<class AGun> StartingGunTemplate = nullptr;

	UPROPERTY(VisibleInstanceOnly, Category = "Gun")
	class AGun* Gun = nullptr;

	UFUNCTION()
	void StartFiringRequest();

	UFUNCTION()
	void StopFiringRequest();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartFiring();

	void StopFiring();

	void InteractWithWeapon();

	virtual void PickGun(class AGun* NewGun);

	void DropGun();
	
	float InteractionDistance = 100.0f;


	//float WeaponDropDistance = 150.0f;

	UPROPERTY(VisibleAnywhere)
	bool bGunCanShoot = true;

	bool bWantsToShoot = false;

	// In process of reloading
	bool bReloading = false;

	bool bReloadingAllowed = true;

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastStartReloading();
	bool MulticastStartReloading_Validate();
	void MulticastStartReloading_Implementation();

	void StartReloading();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastFinishReloading();
	bool MulticastFinishReloading_Validate();
	void MulticastFinishReloading_Implementation();

	void FinishReloading();

	void AttemptFiring();

	FTimerHandle AttemptFiringTimerHandle;

	void SpawnStartingGun();

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;


private:

};
