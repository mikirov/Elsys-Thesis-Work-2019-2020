// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsWidget.generated.h"


class UButton;
class UComboBoxString;

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API USettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UComboBoxString* InputTypeOptions;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UButton* SaveButton;

	UFUNCTION()
	void SaveSettings();
};
