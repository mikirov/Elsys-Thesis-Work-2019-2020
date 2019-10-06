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


protected:

	void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly)
	FName FirstLevelName;

	FName ServerAddress;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* StartGameButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* SettingsButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* QuitButton = nullptr;
	
	/*
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* JoinServerButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UEditableTextBox* ServerTextBox = nullptr;

	*/

	void SetInputModeGameOnly();

	UFUNCTION()
	void StartLevel();

	UFUNCTION()
	void LoadSettingsMenu();

	UFUNCTION()
	void QuitGame();

	UFUNCTION()
	void JoinServer();
};
