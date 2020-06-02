// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBackwardAction.h"
#include "CustomMacros.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"


bool UMoveBackwardAction::Execute_Implementation()
{
	if (validate(IsValid(Pawn)) == false) return false;

	AController* Controller = Pawn->GetController();
	if (validate(IsValid(Controller)) == false) return false;

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	Pawn->AddMovementInput(Direction, -1.0f);

	return true;
}

UMoveBackwardAction::UMoveBackwardAction()
{

}
