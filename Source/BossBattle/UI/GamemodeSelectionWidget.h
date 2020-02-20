// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamemodeSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UGamemodeSelectionWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	//changes the input mode from UI only to game only
	void SetInputModeGameOnly();


	//address of the server to connect by default
	UPROPERTY(EditDefaultsOnly)
	FName ServerAddress;

	//the name of the single player level
	UPROPERTY(EditDefaultsOnly)
	FName SingleplayerMapName;

	void NativeConstruct() override;

	//singleplayer button
	UPROPERTY(meta = (BindWidget))
	class UButton* SingleplayerButton = nullptr;

	//multiplayer button
	UPROPERTY(meta = (BindWidget))
	class UButton* MultiplayerButton = nullptr;

	//back button
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton = nullptr;

	//goes back to main menu
	UFUNCTION()
	void Back();


	//loads singleplayer map
	UFUNCTION()
	void LoadSingleplayer();

	//loads multiplayer map
	UFUNCTION()
	void LoadMultiplayer();
};
