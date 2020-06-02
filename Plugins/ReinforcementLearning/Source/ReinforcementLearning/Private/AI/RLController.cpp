// Fill out your copyright notice in the Description page of Project Settings.


#include "RLController.h"


#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Utilities/CustomMacros.h"

#include "State.h"
#include "Action.h"
#include <limits>

#include "FileHelper.h"
#include "Paths.h"
#include "HAL/FileManager.h"


void ARLController::OnPossess(APawn* InPawn)
{

	UE_LOG(LogTemp, Warning, TEXT("ARLController::OnPossess(APawn* InPawn)"))
	Super::OnPossess(InPawn);


	//add all allowed actions
		
	TArray<UActorComponent*> ActionComponents = GetComponentsByClass(UAction::StaticClass());
	for (UActorComponent* ActionComponent : ActionComponents) {
		UAction* Action = Cast<UAction>(ActionComponent);
		if (validate(IsValid(Action)) == false) return;
		Actions.Add(Action);
	}

	//TODO:
	//add all allowed states


	QTable = new float*[States.Num()];

	for (int i = 0; i < States.Num(); i++) {
		QTable[i] = new float[Actions.Num()];
		for (int j = 0; j < Actions.Num(); j++) {
			QTable[i][j] = 0.0f;
		}
	}

	bPossessed = true;

	DeserializeTable(QTable);

}

void ARLController::TakeAction(int ActionIndex)
{

	UE_LOG(LogTemp, Warning, TEXT("ARLController::TakeAction(int ActionIndex)"))
	bLastActionSuccess = Actions[ActionIndex]->Execute();
	
}

AActor* ARLController::GetClosestEnemy()
{
	UE_LOG(LogTemp, Warning, TEXT("ARLController::GetClosestEnemy()"))
	
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return nullptr;

	APawn* ControlledPawn = GetPawn();

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(World, APawn::StaticClass(), OutActors);

	float CurrentDistance = std::numeric_limits<float>::max();
	AActor* ChosenActor = nullptr;
	for (AActor* Actor : OutActors) {
		
		float DistanceToActor = FVector::Dist(Actor->GetActorLocation(), ControlledPawn->GetActorLocation());
		if (DistanceToActor < CurrentDistance) {
			ChosenActor = Actor;
			CurrentDistance = DistanceToActor;
		}
	}

	return ChosenActor;

}


int ARLController::GetState()
{

	UE_LOG(LogTemp, Warning, TEXT("ARLController::GetState()"))

	int CurrentState = 0;
	for (int i = 0; i < States.Num(); i++) {
		CurrentState += (States[i]->IsSatisfied() * (1 << i));
	}
	return CurrentState;
	
}


void ARLController::GetBestAction(const int CurrentState, int& OutCurrentActionIndex, float& OutCurrentActionValue)
{

	UE_LOG(LogTemp, Warning, TEXT("ARLController::GetBestAction(const int CurrentState, int& OutCurrentActionIndex, float& OutCurrentActionValue)"))

	if (validate(CurrentState < States.Num()) == false) return;
	if (validate(QTable != nullptr) == false) return;
	//get current action values for this state

	//get the action value that gives us the highest reward from our array
	OutCurrentActionValue = QTable[CurrentState][0];
	OutCurrentActionIndex = 0;
	//find max value
	for (int i = 0; i < Actions.Num(); i++) {
		if (QTable[CurrentState][i] > OutCurrentActionValue) {
			OutCurrentActionValue = QTable[CurrentState][i];
			OutCurrentActionIndex = i;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("CurrentState: %d, CurrentActionIndex: %d, CurrentActionValue: %d"), CurrentState, OutCurrentActionIndex, OutCurrentActionValue)
}

void ARLController::DeserializeTable(float** Table)
{
	UE_LOG(LogTemp, Warning, TEXT("ARLController::DeserializeTable(float** Table)"))

	TArray<FString> File;
	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + TEXT("/table.csv");
	bool bSuccess = FFileHelper::LoadANSITextFileToStrings(*FilePath, &IFileManager::Get(), File);
	//if (validate(bSuccess) == false || File.Num() <= StateCount * Actions.size()) {
	if (validate(bSuccess) == false) return;

	validate(File.Num() == States.Num());
	for (int i = 0; i < File.Num(); i++)
	{
		FString Temp = File[i];
		TArray<FString> Values;
		Temp.ParseIntoArray(Values, TEXT(","), false);
		validate(Values.Num() == Actions.Num());
		for (int j = 0; j < Values.Num(); j++) {
			Table[i][j] = FCString::Atof(*Values[j]);
		}

	}

}

void ARLController::SerializeTable(float** Table)
{

	UE_LOG(LogTemp, Warning, TEXT("ARLController::SerializeTable(float** Table)"))

	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + TEXT("/table.csv");
	FString FileContent;
	for (int i = 0; i < States.Num(); i++) {
		for (int j = 0; j < Actions.Num() - 1; j++) {
			FileContent.Append(FString::SanitizeFloat(Table[i][j]));
			FileContent.Append(",");
		}
		FileContent.Append(FString::SanitizeFloat(Table[i][Actions.Num() - 1]));
		FileContent.Append("\n");

	}
	//TODO: maybe tweak flags
	bool bSuccess = FFileHelper::SaveStringToFile(FileContent, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get());
	if (validate(bSuccess) == false) return;
}


void ARLController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

	UE_LOG(LogTemp, Warning, TEXT("ARLController::EndPlay"))


	for (int i = 0; i < States.Num(); i++) {
		delete[] QTable[i];
	}

	delete[] QTable;

	Super::EndPlay(EndPlayReason);
}

