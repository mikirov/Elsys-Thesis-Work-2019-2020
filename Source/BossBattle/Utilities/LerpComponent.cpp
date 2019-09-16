// Fill out your copyright notice in the Description page of Project Settings.

#include "LerpComponent.h"
#include "GameFramework/Actor.h"
#include "Utilities/CustomMacros.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Function.h"

template<class T>
void ULerpComponent::StartLerpCoroutine(
	void(ULerpComponent::*LerpValSetter)(T Value),
	T Start,
	T End,
	float TimeForLerp,
	float PassedTime
) {
	AActor* Owner = GetOwner();
	if (validate(IsValid(Owner)) == false) { return; }

	UWorld* World = Owner->GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	float DeltaTime = World->GetDeltaSeconds();
	PassedTime += DeltaTime;
	if (PassedTime > TimeForLerp) {
		return;
	}

	T Value = FMath::Lerp(Start, End, PassedTime / TimeForLerp);
	(this->*LerpValSetter)(Value);

	FTimerDelegate TimerDelegate;
	TimerDelegate.BindUObject(this, &ULerpComponent::StartLerpCoroutine, LerpValSetter, Start, End, TimeForLerp, PassedTime);

	World->GetTimerManager().SetTimerForNextTick(
		TimerDelegate
	);
}


void ULerpComponent::LerpActorToLocation(FVector EndLocation, float TimeForLerp) {
	if (IsValid(GetOwner()) == false) { return; }

	ULerpComponent::StartLerpCoroutine<FVector>(
		&ULerpComponent::SetActorLocation,
		GetOwner()->GetActorLocation(),
		EndLocation,
		TimeForLerp
	);
}


void ULerpComponent::LerpActorToLocationHorizontal(FVector EndLocation, float TimeForLerp) {
	if (IsValid(GetOwner()) == false) { return; }

	ULerpComponent::StartLerpCoroutine<FVector>(
		&ULerpComponent::SetActorLocationHorizontal,
		GetOwner()->GetActorLocation(),
		EndLocation,
		TimeForLerp
	);
}


void ULerpComponent::SetActorLocation(FVector Value) {
	if (IsValid(GetOwner()) == false) { return; }

	GetOwner()->SetActorLocation(Value);
}


void ULerpComponent::SetActorLocationHorizontal(FVector Value) {
	if (IsValid(GetOwner()) == false) { return; }

	Value.Z = GetOwner()->GetActorLocation().Z;
	GetOwner()->SetActorLocation(Value);
}

void ULerpComponent::LerpActorToRotation(FRotator EndRotation, float TimeForLerp) {
	if (IsValid(GetOwner()) == false) { return; }

	StartLerpCoroutine<FRotator>(
		&ULerpComponent::SetActorRotation,
		GetOwner()->GetActorRotation(),
		EndRotation,
		TimeForLerp
	);
}


void ULerpComponent::SetActorRotation(FRotator Value) {
	if (IsValid(GetOwner()) == false) { return; }

	GetOwner()->SetActorRotation(Value);
}