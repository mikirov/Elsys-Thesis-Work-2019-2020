// Fill out your copyright notice in the Description page of Project Settings.


#include "BattlePlayerState.h"

#include "UI/BattleHUD.h"
#include "UI/ChatWidget.h"
#include "Utilities/CustomMacros.h"


bool ABattlePlayerState::ServerSendMessage_Validate(const FText& Message, const FText& Sender) {
	return true;
}

void ABattlePlayerState::ServerSendMessage_Implementation(const FText& Message, const FText& Sender) {
	MulticastSendMessage(Message, Sender);
}

bool ABattlePlayerState::MulticastSendMessage_Validate(const FText& Message, const FText& Sender) {
	return true;
}

void ABattlePlayerState::MulticastSendMessage_Implementation(const FText& Message, const FText& Sender) {
	
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	ABattleHUD* HUD = Cast<ABattleHUD>(PlayerController->GetHUD());
	if (validate(IsValid(HUD)) == false) return;

	UChatWidget* ChatWidget = HUD->GetChatWidget();
	if (validate(IsValid(ChatWidget)) == false) return;

	ChatWidget->AddMessageWidget(Message, Sender);

}

