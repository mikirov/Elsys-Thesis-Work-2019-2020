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

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* BackButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* GraphicalIncrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* GraphicalDecrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* PPIncrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* PPDecrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* AAIncrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* AADecrementButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* ShadowIncrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* ShadowDecrementButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* FPSIncrementButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
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
	int GraphicalIndex = 2;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int ShadowIndex = 2;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int PPIndex = 2;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int AAIndex = 2;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int FPSIndex = 2;

	UFUNCTION()
	void Back();

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
