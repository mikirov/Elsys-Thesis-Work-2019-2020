// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"
#include "Components/Button.h"
#include "Components/ComboBoxString.h"

#include "Utilities/InputType.h"
#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"


void USettingsWidget::NativeConstruct() {
	Super::NativeConstruct();
	
	MainSettings.Add(FText::FromString("LOW"));
	MainSettings.Add(FText::FromString("MEDIUM"));
	MainSettings.Add(FText::FromString("HIGH"));
	MainSettings.Add(FText::FromString("ULTRA"));

	FPSSettings.Add(FText::FromString("15Hz"));
	FPSSettings.Add(FText::FromString("30Hz"));
	FPSSettings.Add(FText::FromString("60Hz"));
	FPSSettings.Add(FText::FromString("144Hz"));

	GraphicalCommands.Add(FText::FromString("r.ScreenPercentage 25"));
	GraphicalCommands.Add(FText::FromString("r.ScreenPercentage 50"));
	GraphicalCommands.Add(FText::FromString("r.ScreenPercentage 75"));
	GraphicalCommands.Add(FText::FromString("r.ScreenPercentage 100"));

	PPCommands.Add(FText::FromString("sg.PostProcessQuality 0"));
	PPCommands.Add(FText::FromString("sg.PostProcessQuality 1"));
	PPCommands.Add(FText::FromString("sg.PostProcessQuality 2"));
	PPCommands.Add(FText::FromString("sg.PostProcessQuality 3"));

	AACommands.Add(FText::FromString("PostProcessAAQuality 0"));
	AACommands.Add(FText::FromString("PostProcessAAQuality 1"));
	AACommands.Add(FText::FromString("PostProcessAAQuality 2"));
	AACommands.Add(FText::FromString("PostProcessAAQuality 3"));

	ShadowCommands.Add(FText::FromString("sg.ShadowQuality 0"));
	ShadowCommands.Add(FText::FromString("sg.ShadowQuality 1"));
	ShadowCommands.Add(FText::FromString("sg.ShadowQuality 2"));
	ShadowCommands.Add(FText::FromString("sg.ShadowQuality 3"));

	FPSCommands.Add(FText::FromString("t.MaxFPS 15"));
	FPSCommands.Add(FText::FromString("t.MaxFPS 30"));
	FPSCommands.Add(FText::FromString("t.MaxFPS 60"));
	FPSCommands.Add(FText::FromString("t.MaxFPS 144"));
	

	//if (validate(IsValid(BackButton))) {
	//	BackButton->OnPressed.AddDynamic(this, &USettingsWidget::Back);
	//}

	if (validate(IsValid(GraphicalIncrementButton))) {
		GraphicalIncrementButton->OnPressed.AddDynamic(this, &USettingsWidget::IncrementGraphical);
	}
	if (validate(IsValid(GraphicalDecrementButton))) {
		GraphicalDecrementButton->OnPressed.AddDynamic(this, &USettingsWidget::DecrementGraphical);
	}

	if (validate(IsValid(AAIncrementButton))) {
		AAIncrementButton->OnPressed.AddDynamic(this, &USettingsWidget::IncrementAA);
	}
	if (validate(IsValid(AADecrementButton))) {
		AADecrementButton->OnPressed.AddDynamic(this, &USettingsWidget::DecrementAA);
	}

	if (validate(IsValid(PPIncrementButton))) {
		PPIncrementButton->OnPressed.AddDynamic(this, &USettingsWidget::IncrementPP);
	}
	if (validate(IsValid(PPDecrementButton))) {
		PPDecrementButton->OnPressed.AddDynamic(this, &USettingsWidget::DecrementPP);
	}

	if (validate(IsValid(ShadowIncrementButton))) {
		ShadowIncrementButton->OnPressed.AddDynamic(this, &USettingsWidget::IncrementShadow);
	}
	if (validate(IsValid(ShadowDecrementButton))) {
		ShadowDecrementButton->OnPressed.AddDynamic(this, &USettingsWidget::DecrementShadow);
	}


	if (validate(IsValid(FPSIncrementButton))) {
		ShadowIncrementButton->OnPressed.AddDynamic(this, &USettingsWidget::IncrementFPS);
	}
	if (validate(IsValid(FPSDecrementButton))) {
		FPSDecrementButton->OnPressed.AddDynamic(this, &USettingsWidget::DecrementFPS);
	}

}


void USettingsWidget::Back() {
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	World->Exec(World, *GraphicalCommands[GraphicalIndex].ToString());
	World->Exec(World, *AACommands[AAIndex].ToString());
	World->Exec(World, *AACommands[PPIndex].ToString());
	World->Exec(World, *FPSCommands[FPSIndex].ToString());
	World->Exec(World, *ShadowCommands[ShadowIndex].ToString());

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }

	MainMenuHUD->LoadMainMenu();
}

void USettingsWidget::IncrementGraphical() {
	GraphicalIndex = FMath::Clamp(GraphicalIndex + 1, 0, GraphicalCommands.Num() - 1);

}

void USettingsWidget::DecrementGraphical() {
	GraphicalIndex = FMath::Clamp(GraphicalIndex -1, 0, GraphicalCommands.Num() - 1);

}

void USettingsWidget::IncrementAA() {
	AAIndex = FMath::Clamp(AAIndex + 1, 0, AACommands.Num() - 1);
}

void USettingsWidget::DecrementAA() {
	AAIndex = FMath::Clamp(AAIndex - 1, 0, AACommands.Num() - 1);

}

void USettingsWidget::IncrementPP() {
	PPIndex = FMath::Clamp(PPIndex + 1, 0, PPCommands.Num() - 1);

}

void USettingsWidget::DecrementPP() {
	PPIndex = FMath::Clamp(PPIndex - 1, 0, PPCommands.Num() - 1);

}

void USettingsWidget::IncrementFPS() {
	FPSIndex = FMath::Clamp(FPSIndex + 1, 0, FPSCommands.Num() - 1);

}

void USettingsWidget::DecrementFPS() {
	FPSIndex = FMath::Clamp(FPSIndex - 1, 0, FPSCommands.Num() - 1);
}

void USettingsWidget::IncrementShadow() {
	ShadowIndex = FMath::Clamp(ShadowIndex + 1, 0, ShadowCommands.Num() - 1);

}

void USettingsWidget::DecrementShadow() {
	ShadowIndex = FMath::Clamp(ShadowIndex - 1, 0, ShadowCommands.Num() - 1);

}



