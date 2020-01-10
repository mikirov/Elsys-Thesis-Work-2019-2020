// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateMessages(const FText& Messages);

protected:

	void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly)
	FName FirstLevelName;
	
	UPROPERTY(EditDefaultsOnly)
	FName TrainingLevelName;

	UPROPERTY(EditDefaultsOnly)
	FName ServerAddress;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* StartGameButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* SettingsButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* QuitButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* MultiplayerSettingsButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* RLTrainingButton = nullptr;

	void SetInputModeGameOnly();

	void SetInputModeGameAndUI();

	UFUNCTION()
	void StartLevel();

	UFUNCTION()
	void LoadSettingsMenu();

	UFUNCTION()
	void LoadMultiplayerMenu();

	UFUNCTION()
	void QuitGame();

	UFUNCTION()
	void LoadTrainingMap();
};
