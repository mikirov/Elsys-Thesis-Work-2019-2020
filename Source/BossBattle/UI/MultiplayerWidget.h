// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MultiplayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UMultiplayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	//button to create a server
	UPROPERTY(meta = (BindWidget))
	class UButton* CreateServerMenuButton = nullptr;

	//button to search for a server already created
	UPROPERTY(meta = (BindWidget))
	class UButton* FindServerMenuButton = nullptr;

	//button to join a server
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinServerMenuButton = nullptr;

	//button to go back to the main menu
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton = nullptr;
	

	//widget box showing create server UI
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* CreateServerBox = nullptr;
	
	//widget box for showing find server UI
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* FindServerBox = nullptr;
	
	//widget box for showing join server UI
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* JoinServerBox = nullptr;
	


	void NativeConstruct() override;

	//go back to main menu
	UFUNCTION()
	void Back();

	//shows the find server UI
	UFUNCTION()
	void OpenFindServerBox();

	//shows the create server UI
	UFUNCTION()
	void OpenCreateServerBox();

	//shows the join server UI
	UFUNCTION()
	void OpenJoinServerBox();
};
