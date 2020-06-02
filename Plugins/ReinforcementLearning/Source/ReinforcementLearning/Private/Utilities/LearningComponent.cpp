// Fill out your copyright notice in the Description page of Project Settings.


#include "LearningComponent.h"
#include "TrainingGameMode.h"

#include "TimerManager.h"
#include "Utilities/CustomMacros.h"
#include "Engine/World.h"
// Sets default values for this component's properties
ULearningComponent::ULearningComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}
