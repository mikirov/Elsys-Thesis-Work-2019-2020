// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TrainingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ATrainingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	void SetRLSpawnTransform(const FTransform& Transform);

	 FTransform GetRLSpawnTransform() const;

	void SetAISpawnTransform(const FTransform& Transform);

	FTransform GetAISpawnTransform() const;
	
	void RespawnRLCharacter();

	void RespawnAICharacter();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AAIEnemyCharacter> AIEnemyTemplate;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ARLEnemyCharacter> RLEnemyTemplate;

	void ResetCharacters(bool bAICharacterDied);
	
	UFUNCTION(BlueprintCallable)
	int GetAIKills() const;

	UFUNCTION(BlueprintCallable)
	int GetRLKills() const;

private:

	FTransform AISpawnTransform;

	FTransform RLSpawnTransform;

	int AIKills = 0;

	int RLKills = 0;

};
