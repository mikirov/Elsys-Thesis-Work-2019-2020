// Fill out your copyright notice in the Description page of Project Settings.


#include "RLGameController.h"

#include "Kismet/GameplayStatics.h"

#include "Utilities/CustomMacros.h"

void ARLGameController::BeginPlay()
{
	Super::BeginPlay();

	DeserializeTable(QTable);
}

void ARLGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentStateIndex = GetState();
	validate(CurrentStateIndex >= 0);

	GetBestAction(CurrentStateIndex, CurrentActionIndex, CurrentActionValue);
	validate(CurrentActionIndex >= 0);

	TakeAction(CurrentActionIndex);

}
