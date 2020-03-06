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

	

protected:


	void Logout(AController* Exiting) override;

	void LoadLobby();

	UPROPERTY(BlueprintReadWrite)
	FString LobbyMapName = "Weapons";

	void BeginPlay() override;

	void WinGame() override;

	void UpdateHUDScore(int Score) override;

	int CurrentPlayers = 4;

};
