// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MessageWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UMessageWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetMessage(const FText& Message, const FText& Sender);

protected:

	//message to be displayed
	UPROPERTY(BlueprintReadOnly, Category = UI)
	FText Message;

	//sender of the message
	UPROPERTY(BlueprintReadOnly, Category = UI)
	FText Sender;

};
