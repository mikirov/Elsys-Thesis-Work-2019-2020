#include "TrainingSaveGame.h"

UTrainingSaveGame::UTrainingSaveGame()
{
	SaveSlotName = "Training";
	UserIndex = 0;
}

FString UTrainingSaveGame::GetSaveSlotName()
{
	return SaveSlotName;
}

uint32 UTrainingSaveGame::GetUserIndex()
{
	return UserIndex;
}
