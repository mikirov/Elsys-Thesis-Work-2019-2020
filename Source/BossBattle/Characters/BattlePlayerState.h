// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BattlePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ABattlePlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSendMessage(const FText& Message, const FText& Sender);
	bool ServerSendMessage_Validate(const FText& Message, const  FText& Sender);
	void ServerSendMessage_Implementation(const FText& Message, const FText& Sender);

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MulticastSendMessage(const FText& Message, const FText& Sender);
	bool MulticastSendMessage_Validate(const FText& Message, const FText& Sender);
	void MulticastSendMessage_Implementation(const FText& Message, const FText& Sender);

	UFUNCTION(Exec)
	void StartGame();

	UFUNCTION(Server, Reliable, WithValidation)
	void SendStartCommand(const FString& Command);
	bool SendStartCommand_Validate(const FString& Command);
	void SendStartCommand_Implementation(const FString& Command);
};
