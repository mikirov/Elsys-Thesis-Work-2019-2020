// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LearningComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReset);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REINFORCEMENTLEARNING_API ULearningComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULearningComponent();

	UPROPERTY(BlueprintCallable)
	FDeath OnDeath;


	UPROPERTY(BlueprintCallable)
	FReset OnReset;


};
