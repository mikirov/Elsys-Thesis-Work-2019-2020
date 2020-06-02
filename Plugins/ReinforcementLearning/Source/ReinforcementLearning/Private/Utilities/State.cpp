// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"

#include "Gameframework/Pawn.h"
#include "GameFramework/Controller.h"
#include "Utilities/CustomMacros.h"

UState::UState()
{

}

void UState::BeginPlay()
{

}

bool UState::IsSatisfied_Implementation()
{

	UE_LOG(LogTemp, Warning, TEXT("UState::IsSatisfied_Implementation"))
	return true;
}

float UState::GetReward()
{
	return IsSatisfied() ? PotentialAmount : 0.0f;
}
