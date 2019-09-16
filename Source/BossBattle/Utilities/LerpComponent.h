// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LerpComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOSSBATTLE_API ULerpComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void LerpActorToLocation(FVector EndLocation, float TimeForLerp);

	// TODO: Should probably rework entire lerp component instead of doing it so lazily.
	void LerpActorToLocationHorizontal(FVector EndLocation, float TimeForLerp);

	void LerpActorToRotation(FRotator EndLocation, float TimeForLerp);

protected:

	template<class T>
	void StartLerpCoroutine(void (ULerpComponent::*LerpValSetter)(T Value), T Start, T End, float TimeForLerp, float PassedTime = 0);

	void SetActorLocation(FVector Value);

	void SetActorLocationHorizontal(FVector Value);

	void SetActorRotation(FRotator Value);
		
};
