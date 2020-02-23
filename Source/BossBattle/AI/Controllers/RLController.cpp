// Fill out your copyright notice in the Description page of Project Settings.


#include "RLController.h"


#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Characters/AIEnemyCharacter.h"
#include "Characters/RLTrainingCharacter.h"
#include "Utilities/CustomMacros.h"

#include "Utilities/MoveForwardAction.h"
#include "Utilities/MoveBackwardAction.h"
#include "Utilities/MoveLeftAction.h"
#include "Utilities/MoveRightAction.h"
#include "Utilities/ShootEnemyAction.h"
#include "Utilities/FocusOnEnemyAction.h"
#include "Utilities/ReloadAction.h"
#include "Utilities/InteractAction.h"
#include "Utilities/Action.h"


#include "FileHelper.h"
#include "Paths.h"
#include "HAL/FileManager.h"


void ARLController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	

	ARLTrainingCharacter* RLCharacter = Cast<ARLTrainingCharacter>(InPawn);
	if (validate(IsValid(RLCharacter)) == false) return;

	Actions.push_back(new MoveForwardAction(RLCharacter));
	Actions.push_back(new MoveBackwardAction(RLCharacter));
	Actions.push_back(new MoveLeftAction(RLCharacter));
	Actions.push_back(new MoveRightAction(RLCharacter));
	Actions.push_back(new FocusOnEnemyAction(RLCharacter));
	Actions.push_back(new ShootEnemyAction(RLCharacter));
	Actions.push_back(new InteractAction(RLCharacter));
	Actions.push_back(new ReloadAction(RLCharacter));

	QTable = new float*[StateCount];

	for (int i = 0; i < StateCount; i++) {
		QTable[i] = new float[Actions.size()];
		for (int j = 0; j < Actions.size(); j++) {
			QTable[i][j] = 0.0f;
		}
	}

	DeserializeTable(QTable);

	UE_LOG(LogTemp, Warning, TEXT("Actions: %d"), Actions.size())
}

void ARLController::TakeAction(int ActionIndex)
{
	Actions[ActionIndex]->Execute();
}

int ARLController::GetState()
{
	// taking current state
	//get dealing damage flag, the other two flags are calculated on taking damage event
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return -1;

	bool bDealingDamage = false;

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(World, AAIEnemyCharacter::StaticClass(), OutActors);
	for (auto Actor : OutActors) {
		AAIEnemyCharacter* AICharacter = Cast<AAIEnemyCharacter>(Actor);
		if (AICharacter->IsTakingDamage()) {
			bDealingDamage = true;
		}
	}
	
	ARLEnemyCharacter* RLCharacter = Cast<ARLEnemyCharacter>(GetPawn());
	if (validate(IsValid(RLCharacter)) == false) return -1;


	int CurrentState = (bDealingDamage * 4) + RLCharacter->IsTakingDamage() * 2 + RLCharacter->IsOnCriticalHealth(); // binary flags to integer

	return CurrentState;
}

void ARLController::GetBestAction(const int CurrentState, int& OutCurrentActionIndex, float& OutCurrentActionValue)
{
	if (validate(CurrentState < StateCount) == false) return;
	//get current action values for this state

	//get the action value that gives us the highest reward from our array
	OutCurrentActionValue = QTable[CurrentState][0];
	OutCurrentActionIndex = 0;
	//find max value
	for (int i = 0; i < Actions.size(); i++) {
		if (QTable[CurrentState][i] > OutCurrentActionValue) {
			OutCurrentActionValue = QTable[CurrentState][i];
			OutCurrentActionIndex = i;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("CurrentState: %d, CurrentActionIndex: %d, CurrentActionValue: %d"), CurrentState, OutCurrentActionIndex, OutCurrentActionValue)
}

void ARLController::DeserializeTable(float** Table)
{
	TArray<FString> File;

	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + TEXT("/table.csv");
	bool bSuccess = FFileHelper::LoadANSITextFileToStrings(*FilePath, &IFileManager::Get(), File);
	//if (validate(bSuccess) == false || File.Num() <= StateCount * Actions.size()) {
	if (validate(bSuccess) == false) return;

	validate(File.Num() == StateCount);
	for (int i = 0; i < File.Num(); i++)
	{
		FString Temp = File[i];
		TArray<FString> Values;
		Temp.ParseIntoArray(Values, TEXT(","), false);
		validate(Values.Num() == Actions.size());
		for (int j = 0; j < Values.Num(); j++) {
			Table[i][j] = FCString::Atof(*Values[j]);
		}

	}


}

void ARLController::SerializeTable(float** Table)
{

	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + TEXT("/table.csv");

	FString FileContent;
	for (int i = 0; i < StateCount; i++) {
		for (int j = 0; j < Actions.size() - 1; j++) {
			FileContent.Append(FString::SanitizeFloat(Table[i][j]));
			FileContent.Append(",");
		}
		FileContent.Append(FString::SanitizeFloat(Table[i][Actions.size() - 1]));
		FileContent.Append("\n");

	}
	//TODO: maybe tweak flags
	bool bSuccess = FFileHelper::SaveStringToFile(FileContent, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get());
	if (validate(bSuccess) == false) return;
}
