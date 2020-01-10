// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UFUNCTION(Client, Reliable, WithValidation)
	void OnWinGame();
	bool OnWinGame_Validate();
	void OnWinGame_Implementation();

	UFUNCTION(Client, Reliable, WithValidation)
	void OnLoseGame();
	bool OnLoseGame_Validate();
	void OnLoseGame_Implementation();

	bool HasEverDied();

	void SetHasEverDied(bool State);

	void LoadWinLevel();

	void LoadLoseLevel();

protected:

	UPROPERTY(EditDefaultsOnly)
	FString MapsFolderPath;

	UPROPERTY(EditDefaultsOnly)
	FString WinGameLevelName;

	UPROPERTY(EditDefaultsOnly)
	float LoadEndLevelDelay = 1.5f;

	bool bHasEverDied = false;
};
