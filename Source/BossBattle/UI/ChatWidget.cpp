// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"

#include "Utilities/CustomMacros.h"
#include "Characters/BattlePlayerState.h"
#include "UI/MessageWidget.h"


void UChatWidget::NativeConstruct() {

	Super::NativeConstruct();
	if (validate(IsValid(CloseButton))) {
		CloseButton->OnClicked.AddDynamic(this, &UChatWidget::Close);

	}
	if (validate(IsValid(TextBox))) {
		TextBox->OnTextCommitted.AddDynamic(this, &UChatWidget::HandleOnTextCommitted);
	}
	PlayAnimation(OpenCloseAnimation, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f);

}

void UChatWidget::AddMessageWidget(const FText& Message, const FText& Sender) {
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	
	
	if(validate(IsValid(ScrollBox)) == false) return;

	UMessageWidget* MessageWidget = Cast<UMessageWidget>(CreateWidget(World, MessageTemplate));
	if (validate(IsValid(MessageWidget)) == false) return;

	MessageWidget->SetMessage(Message, Sender);

	ScrollBox->AddChild(MessageWidget);
}

void UChatWidget::Tick(FGeometry MyGeometry, float InDeltaTime) {
	Super::Tick(MyGeometry, InDeltaTime);

}

void UChatWidget::HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod) {

	UE_LOG(LogTemp, Warning, TEXT("UChatWidget::HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)"))
	if (CommitMethod == ETextCommit::OnEnter && !Text.EqualTo(FText::FromString(""))) {
		UE_LOG(LogTemp, Warning, TEXT("CommitMethod == ETextCommit::OnEnter && !Text.EqualTo(FText::FromString(""))"))
		ABattlePlayerState* PlayerState = Cast<ABattlePlayerState>(GetOwningPlayerState());
		if (validate(IsValid(PlayerState))) {
			PlayerState->ServerSendMessage(Text, FText::FromString(PlayerState->GetPlayerName()));

		}
	}
}

void UChatWidget::Close() {
	PlayAnimation(OpenCloseAnimation, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f);

	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController))) {
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		PlayerController->bShowMouseCursor = false;
	}
}

UWidgetAnimation* UChatWidget::GetChatAnimation() const {
	if (validate(IsValid(OpenCloseAnimation))) {
		return OpenCloseAnimation;
	}
	return nullptr;
}