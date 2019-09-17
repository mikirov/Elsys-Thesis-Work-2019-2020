// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"
#include "Components/Button.h"
#include "Components/ComboBoxString.h"

#include "Utilities/InputType.h"
#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"


void USettingsWidget::NativeConstruct() {
	Super::NativeConstruct();

	if (validate(IsValid(InputTypeOptions))) {
		UEnum* InputTypeEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("InputType"), true);
		if (validate(IsValid(InputTypeEnum))) {
			// NumEnums() - 1 because last one is added by reflection system
			for (int i = 0; i < InputTypeEnum->NumEnums() - 1; i++) {
				FString Name = InputTypeEnum->GetNameStringByIndex(i);
				if (validate(Name != FString("")) == false) { break; }

				InputTypeOptions->AddOption(Name);
			}
			InputTypeOptions->SetSelectedOption(InputTypeEnum->GetNameStringByIndex(0));
		}
	}


	if (validate(IsValid(SaveButton))) {
		SaveButton->OnPressed.AddDynamic(this, &USettingsWidget::SaveSettings);
	}
}


void USettingsWidget::SaveSettings() {
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }
	if (validate(IsValid(InputTypeOptions)) == false) { return; }
	
	InputType Type = (InputType) InputTypeOptions->FindOptionIndex(InputTypeOptions->GetSelectedOption());
	MainMenuHUD->SaveSettings();
	

	MainMenuHUD->LoadMainMenu();
}