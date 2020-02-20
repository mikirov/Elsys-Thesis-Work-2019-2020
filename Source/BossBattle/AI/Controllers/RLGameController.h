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

	//loads the trained q-table
	void BeginPlay();

	//choses an action based on the q-tale values
	void Tick(float DeltaTime);

};
