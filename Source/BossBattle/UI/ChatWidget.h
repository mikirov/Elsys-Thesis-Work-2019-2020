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
	UWidgetAnimation* GetChatAnimation() const;
	
	void AddMessageWidget(const FText& Message, const FText& Sender);

protected:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = UI)
	class UWidgetAnimation* OpenCloseAnimation = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = UI)
	class UButton* CloseButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = UI)
	class UEditableTextBox* TextBox = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = UI)
	class UScrollBox* ScrollBox= nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> MessageTemplate;

	void NativeConstruct() override;

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

	UFUNCTION()
	void Close();


};
