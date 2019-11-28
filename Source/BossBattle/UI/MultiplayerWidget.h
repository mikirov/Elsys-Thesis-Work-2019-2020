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

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* CreateServerMenuButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* FindServerMenuButton = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* JoinServerMenuButton = nullptr;


	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UButton* BackButton = nullptr;
	

	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UVerticalBox* CreateServerBox = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UVerticalBox* FindServerBox = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UVerticalBox* JoinServerBox = nullptr;
	


	void NativeConstruct() override;

	UFUNCTION()
	void Back();

	UFUNCTION()
	void OpenFindServerBox();

	UFUNCTION()
	void OpenCreateServerBox();

	UFUNCTION()
	void OpenJoinServerBox();
};
