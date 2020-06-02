// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TrainingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REINFORCEMENTLEARNING_API ATrainingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	public:

	UFUNCTION(BlueprintCallable)
	void ResetCharacters();

	void BeginPlay() override;

	UFUNCTION()
	void DecrementEnemyCounter();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APawn> RLEnemyTemplate;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APawn> AIEnemyTemplate;

	UPROPERTY(EditDefaultsOnly)
	TArray<FTransform> InitialAITransforms;

	UPROPERTY(EditDefaultsOnly)
	FTransform InitialRLTransform;

	int CurrentEnemies = 0;

	TArray<class APawn*> AIPawns;
	
	class APawn* RLPawn = nullptr;
};
