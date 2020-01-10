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

	UPROPERTY(BlueprintReadOnly, Category = UI)
	FText Message;

	UPROPERTY(BlueprintReadOnly, Category = UI)
	FText Sender;

};
