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
	UE_LOG(LogTemp, Warning, TEXT("UChatWidget::NativeConstruct()"))


	bOpen = false;
	if (validate(IsValid(CloseButton))) {
		CloseButton->OnClicked.AddDynamic(this, &UChatWidget::Close);

	}
	if (validate(IsValid(TextBox))) {
		TextBox->OnTextCommitted.AddDynamic(this, &UChatWidget::HandleOnTextCommitted);
	}
	Close();

}

void UChatWidget::AddMessageWidget(const FText& Message, const FText& Sender) {
	
	UE_LOG(LogTemp, Warning, TEXT("UChatWidget::AddMessageWidget(const FText& Message, const FText& Sender)"))

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;
	
	
	if(validate(IsValid(ScrollBox)) == false) return;

	UMessageWidget* MessageWidget = Cast<UMessageWidget>(CreateWidget(World, MessageTemplate));
	if (validate(IsValid(MessageWidget)) == false) return;

	MessageWidget->SetMessage(Message, Sender);

	ScrollBox->AddChild(MessageWidget);
}

class UEditableTextBox* UChatWidget::GetInputBox()
{
	return TextBox;
}

void UChatWidget::Tick(FGeometry MyGeometry, float InDeltaTime) {
	Super::Tick(MyGeometry, InDeltaTime);

}

void UChatWidget::HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod) {

	UE_LOG(LogTemp, Warning, TEXT("UChatWidget::HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)"))
	if (CommitMethod == ETextCommit::OnEnter && !Text.EqualTo(FText::FromString(""))) {
		//UE_LOG(LogTemp, Warning, TEXT("CommitMethod == ETextCommit::OnEnter && !Text.EqualTo(FText::FromString(""))"))
		ABattlePlayerState* PlayerState = Cast<ABattlePlayerState>(GetOwningPlayerState());
		if (validate(IsValid(PlayerState))) {
			PlayerState->ServerSendMessage(Text, FText::FromString(PlayerState->GetPlayerName()));

		}
		if (validate(IsValid(TextBox))) {
			FText TextToSet;
			TextBox->SetText(TextToSet);
		}
	}

	if (validate(IsValid(ScrollBox)) == false) return;
	ScrollBox->ScrollToEnd();
}

void UChatWidget::Close() {


	UE_LOG(LogTemp, Warning, TEXT("UChatWidget::Close()"))
	bOpen = false;
	PlayAnimation(OpenCloseAnimation, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f);

	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController))) {
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		PlayerController->bShowMouseCursor = false;
	}

}

bool UChatWidget::IsOpen()
{

	UE_LOG(LogTemp, Warning, TEXT("bool UChatWidget::IsOpen()"))
	return bOpen;
}

void UChatWidget::Open()
{
	UE_LOG(LogTemp, Warning, TEXT("UChatWidget::Open()"))

	bOpen = true;
	
	APlayerController* PlayerController = Cast<APlayerController>(GetOwningPlayer());
	if (validate(IsValid(PlayerController))) {
		PlayerController->bShowMouseCursor = true;

		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	}
	PlayAnimation(OpenCloseAnimation, 0.0f, 1, EUMGSequencePlayMode::Reverse, 1.0f);

	if (validate(IsValid(TextBox)) == false) return;
	TextBox->SetKeyboardFocus();

	if (validate(IsValid(ScrollBox)) == false) return;
	ScrollBox->ScrollToEnd();
}