// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MultiplayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UMultiplayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:


	//button to go back to the main menu
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton = nullptr;
	



	void NativeConstruct() override;

	//go back to main menu
	UFUNCTION()
	void Back();


};
