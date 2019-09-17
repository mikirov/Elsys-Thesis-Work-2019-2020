// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"


class UButton;
class USettingsWidget;

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
	UButton* StartGameButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UButton* SettingsButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UButton* JoinServerButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UEditableTextBox* ServerTextBox = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UButton* QuitButton = nullptr;

	UFUNCTION()
	void StartLevel();

	UFUNCTION()
	void LoadSettingsMenu();

	UFUNCTION()
	void QuitGame();

	UFUNCTION()
	void JoinServer();
};
