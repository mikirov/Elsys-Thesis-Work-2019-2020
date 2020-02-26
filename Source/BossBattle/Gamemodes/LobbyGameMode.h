// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ALobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()


private:

	virtual void GetSeamlessTravelActorList
	(
		bool bToTransition,
		TArray< AActor * > & ActorList
	) override;

	void BeginPlay() override;

	void PostLogin(class APlayerController* PlayerController) override;

	void PreLogin
	(
		const FString& Options,
		const FString& Address,
		const FUniqueNetIdRepl& UniqueId,
		FString& ErrorMessage
	) override;

	void Logout(AController* Exiting) override;



	//current players count
	int CurrentPlayers = 0;

	// max players count
	UPROPERTY(EditDefaultsOnly)
	int MaxPlayersCount = 4;



protected:

	UPROPERTY(BlueprintReadWrite)
	FString MainMapName = "MainMap";

	UPROPERTY(BlueprintReadWrite)
	FString LobbyMapName = "Weapons";

};
