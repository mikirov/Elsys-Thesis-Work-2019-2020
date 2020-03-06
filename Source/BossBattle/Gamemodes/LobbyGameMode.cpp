// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "Characters/PlayerCharacterController.h"
#include "Characters/PlayerCharacter.h"
#include "Weapons/Gun.h"
#include "Utilities/CustomMacros.h"
#include "Engine/World.h"

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();
	//bUseSeamlessTravel = true;

	if (validate(MainMapName.Len() > 0) == false) return;
	if (validate(LobbyMapName.Len() > 0) == false) return;

	UE_LOG(LogTemp, Warning, TEXT("ALobbyGameMode::BeginPlay()"))
}

void ALobbyGameMode::PostLogin(class APlayerController* PlayerController)
{
	
	Super::PostLogin(PlayerController);

	CurrentPlayers++;

	UE_LOG(LogTemp, Warning, TEXT("ALobbyGameMode::PostLogin(class APlayerController* PlayerController) CurrentPlayers: %d"), CurrentPlayers);
	if (CurrentPlayers == MaxPlayersCount) {
		UWorld* World = GetWorld();
		if (validate(IsValid(World)) == false) return;

		if (validate(MainMapName.Len() > 0) == false) return;

		World->ServerTravel(MainMapName);

	}
}

void ALobbyGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UE_LOG(LogTemp, Warning, TEXT("ALobbyGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)"));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);


	if (CurrentPlayers >= MaxPlayersCount) {
		ErrorMessage = "Cannot join";
	}

}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	CurrentPlayers--;
	UE_LOG(LogTemp, Warning, TEXT("ALobbyGameMode::Logout(AController* Exiting) CurrentPlayers: %d"), CurrentPlayers)

}