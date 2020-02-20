// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gamemodes/PlayingGameMode.h"
#include "MultiplayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API AMultiplayerGameMode : public APlayingGameMode
{
	GENERATED_BODY()
	
public:

	void OnPlayerDeath(class APlayerCharacterController* PlayerController) override;

	TArray<class APlayerCharacterController*> GetPlayerControllers() override;


protected:

	void BeginPlay() override;

	void WinGame() override;

	void PostLogin(class APlayerController* PlayerController) override;
	
	void PreLogin
	(
		const FString & Options,
		const FString & Address,
		const FUniqueNetIdRepl & UniqueId,
		FString & ErrorMessage
	) override;

	void Logout(AController* Exiting) override;

	int CurrentPlayers = 0;

	void UpdateHUDScore(int Score) override;

	UPROPERTY(BlueprintReadWrite)
	TArray<class APlayerCharacterController*> PlayerControllers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int MaxPlayersCount = 4;

	bool bPlaying = false;
};
