// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TrainingStatsWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UTrainingStatsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	void NativeConstruct() override;

	//back to main menu button
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton = nullptr;
	
	//reset the q-table button
	UPROPERTY(meta = (BindWidget))
	class UButton* ResetButton = nullptr;

	//goes back to main menu
	UFUNCTION()
	void Back();

	//resets the training
	UFUNCTION()
	void Reset();

};
