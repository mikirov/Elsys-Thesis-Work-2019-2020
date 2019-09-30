// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WinMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UWinMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected :

	void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly)
	FName RestartLevelName;

	UPROPERTY(EditDefaultsOnly)
	FName MainMenuLevelName;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* QuitButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* RestartGameButton = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* MainMenuButton = nullptr;

	void SetInputModeGameOnly();

	UFUNCTION()
	void QuitGame();

	UFUNCTION()
	void RestartGame();

	UFUNCTION()
	void LoadMainMenu();


};
