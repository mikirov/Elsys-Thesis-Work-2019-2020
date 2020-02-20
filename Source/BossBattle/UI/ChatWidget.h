// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChatWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UChatWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//adds a widget child to the scrolbox widget 
	void AddMessageWidget(const FText& Message, const FText& Sender);

	class UEditableTextBox* GetInputBox();

	//close the chat
	UFUNCTION()
	void Close();

	bool IsOpen();

	void Open();

protected:

	//open and close chat animation
	UPROPERTY(BlueprintReadWrite, Category = UI)
	class UWidgetAnimation* OpenCloseAnimation = nullptr;


private:

	bool bOpen = false;


	//button to close the chat
	UPROPERTY(meta = (BindWidget))
	class UButton* CloseButton = nullptr;
	
	//input box for the chat
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* TextBox = nullptr;

	//scrol feed with chat messages
	UPROPERTY(meta = (BindWidget))
	class UScrollBox* ScrollBox = nullptr;

	//template of the single message widget
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> MessageTemplate;

	void NativeConstruct() override;

	//called when text gets committed ( with enter)
	UFUNCTION()
	void HandleOnTextCommitted
	(
		const FText& Text,
		ETextCommit::Type CommitMethod
	);

	void Tick
	(
		FGeometry MyGeometry,
		float InDeltaTime
	);


};
