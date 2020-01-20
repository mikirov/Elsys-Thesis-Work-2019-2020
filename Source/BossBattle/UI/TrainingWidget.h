// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TrainingWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UTrainingWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
protected:

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* AITrainingButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* RLTrainingButton = nullptr;


	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* BackButton = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FName AITrainingLevelName;
	
	UPROPERTY(EditDefaultsOnly)
	FName RLTrainingLevelName;

	void NativeConstruct();

	UFUNCTION()
	void Back();

	UFUNCTION()
	void LoadAITraining();

	UFUNCTION()
	void LoadRLTraining();
	
};
