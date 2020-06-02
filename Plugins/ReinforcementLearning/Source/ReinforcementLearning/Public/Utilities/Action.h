// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Action.generated.h"
/**
 * 
 */


UCLASS(BLueprintable)
class REINFORCEMENTLEARNING_API UAction : public UActorComponent
{
	GENERATED_BODY()
public:


	
	UAction();

	void BeginPlay();

	//execute method overridden by every action
	UFUNCTION(BlueprintImplementableEvent)
	bool Execute();
	

	virtual bool Execute_Implementation();
	
	UFUNCTION(BlueprintCallable)
	class APawn* GetPawn() const { return Pawn; }
	void SetPawn(class APawn* val) { Pawn = val; }
protected:
	class APawn* Pawn = nullptr;
};	