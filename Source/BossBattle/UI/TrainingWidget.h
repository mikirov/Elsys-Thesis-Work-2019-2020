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

	// AI training map button
	UPROPERTY(meta = (BindWidget))
	class UButton* AITrainingButton = nullptr;

	//RL vs RL training map button
	UPROPERTY(meta = (BindWidget))
	class UButton* RLTrainingButton = nullptr;

	//back to main menu button
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton = nullptr;

	//RL vs AI training level name
	UPROPERTY(EditDefaultsOnly)
	FName AITrainingLevelName;
	
	//RL vs RL training level name
	UPROPERTY(EditDefaultsOnly)
	FName RLTrainingLevelName;

	void NativeConstruct() override;

	//goes back to main menu
	UFUNCTION()
	void Back();

	//loads RL vs AI training map
	UFUNCTION()
	void LoadAITraining();

	//loads RL vs RL training map
	UFUNCTION()
	void LoadRLTraining();
	
};
