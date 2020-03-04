// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Controllers/RLController.h"
#include "RLGameController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ARLGameController : public ARLController
{
	GENERATED_BODY()
	
protected:

	//choses an action based on the q-tale values
	void Tick(float DeltaTime) override;

	void OnPossess(APawn* InPawn) override;

	//called when the actor is destroyed or the game ends
	void EndPlay
	(
		const EEndPlayReason::Type EndPlayReason
	) override;

};
