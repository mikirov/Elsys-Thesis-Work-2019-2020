// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseMenuHUD.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"


#include "UI/LoseMenuWidget.h"
#include "Utilities/CustomMacros.h"

void ALoseMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	LoadLoseMenuWidget();

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, LoseMenuWidget, EMouseLockMode::DoNotLock);

	PlayerController->bShowMouseCursor = true;

}

void ALoseMenuHUD::LoadLoseMenuWidget()
{
	if (validate(IsValid(LoseMenuWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	LoseMenuWidget = Cast<ULoseMenuWidget>(CreateWidget(World, LoseMenuWidgetTemplate));
	if (validate(IsValid(LoseMenuWidget)) == false) { return; }


	LoseMenuWidget->AddToViewport();
}
