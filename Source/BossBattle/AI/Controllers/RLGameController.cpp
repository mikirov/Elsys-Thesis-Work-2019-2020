// Fill out your copyright notice in the Description page of Project Settings.


#include "RLGameController.h"

#include "Kismet/GameplayStatics.h"

#include "Utilities/TableSaveGame.h"
#include "Utilities/CustomMacros.h"

void ARLGameController::BeginPlay()
{
	Super::BeginPlay();

	UTableSaveGame* LoadedTable = Cast<UTableSaveGame>(UGameplayStatics::LoadGameFromSlot(FString::FromInt(0), 0));
	if (validate(IsValid(LoadedTable))) {
		QTable = LoadedTable->QTable;
	}
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
