// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsWidget.generated.h"


/**
 * 
 */
UCLASS()
class BOSSBATTLE_API USettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(meta = (BindWidget))
	class UButton* GraphicalIncrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* GraphicalDecrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* PPIncrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* PPDecrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* AAIncrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* AADecrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* ShadowIncrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* ShadowDecrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* FPSIncrementButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* FPSDecrementButton = nullptr;


	void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> MainSettings;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> FPSSettings;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> GraphicalCommands;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> PPCommands;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> AACommands;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> ShadowCommands;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	TArray<FText> FPSCommands;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int GraphicalIndex;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int ShadowIndex;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int PPIndex;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int AAIndex;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int FPSIndex;

	UFUNCTION(BlueprintCallable)
	void SaveSettings();

	UFUNCTION()
	void IncrementGraphical();

	UFUNCTION()
	void DecrementGraphical();

	UFUNCTION()
	void IncrementShadow();

	UFUNCTION()
	void DecrementShadow();

	UFUNCTION()
	void IncrementPP();

	UFUNCTION()
	void DecrementPP();

	UFUNCTION()
	void IncrementAA();

	UFUNCTION()
	void DecrementAA();

	UFUNCTION()
	void IncrementFPS();

	UFUNCTION()
	void DecrementFPS();

};
