// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "Gameframework/Pawn.h"
#include "GameFramework/Controller.h"
#include "Utilities/CustomMacros.h"

UAction::UAction()
{

}

void UAction::BeginPlay()
{
	Super::BeginPlay();

	AController* PawnController = Cast<AController>(GetOwner());
	if (validate(IsValid(PawnController)) == false) return;
	Pawn = PawnController->GetPawn();
	if (validate(IsValid(Pawn)) == false) return;

}

bool UAction::Execute_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("UAction::Execute_Implementation"))
	return true;
}
