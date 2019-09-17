// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BattleCharacter.h"
#include "EnemyCharacter.generated.h"


UCLASS()
class BOSSBATTLE_API AEnemyCharacter : public ABattleCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	void SetTarget(AActor* Target);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Die();

	UFUNCTION()
	void OnCapsuleHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	// Added score when enemy dies.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float Score = 500.0f;

	// target player used for checking collision actor
	UPROPERTY()
	AActor* Target = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float PushBackMagnitude = 500.0f;

};
