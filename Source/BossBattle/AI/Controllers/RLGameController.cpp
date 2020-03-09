// Fill out your copyright notice in the Description page of Project Settings.


#include "RLGameController.h"

#include "Kismet/GameplayStatics.h"

#include "Utilities/CustomMacros.h"


void ARLGameController::Tick(float DeltaTime)
{
	if (bPossessed == false) return;

	Super::Tick(DeltaTime);

	CurrentStateIndex = GetState();
	if (validate(CurrentStateIndex >= 0 && CurrentStateIndex < StateCount) == false) return;

	GetBestAction(CurrentStateIndex, CurrentActionIndex, CurrentActionValue);
	if (validate(CurrentActionIndex >= 0 && CurrentActionIndex < Actions.size()) == false) return;

	TakeAction(CurrentActionIndex);


}

void ARLGameController::OnPossess(APawn* InPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("ARLTrainingController::OnPossess(APawn* InPawn)"))

	Super::OnPossess(InPawn);

}

void ARLGameController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("ARLGameController::EndPlay"))

	Super::EndPlay(EndPlayReason);
}
