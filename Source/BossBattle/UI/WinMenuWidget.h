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
	FName ServerAddress;

	UPROPERTY(EditDefaultsOnly)
	FName MainMenuLevelName;

	UPROPERTY(EditDefaultsOnly)
	FName RestartLevelName;


	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* RestartGameButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* MainMenuButton = nullptr;

	void SetInputModeGameOnly();

	UFUNCTION()
	void QuitGame();

	UFUNCTION()
	void RestartGame();

	UFUNCTION()
	void LoadMainMenu();


};
