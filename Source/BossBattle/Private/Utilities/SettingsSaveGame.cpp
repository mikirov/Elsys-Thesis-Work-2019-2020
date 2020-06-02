// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsSaveGame.h"

USettingsSaveGame::USettingsSaveGame() {
	

	SaveSlotName = "Settings";
	UserIndex = 0;
}

FString USettingsSaveGame::GetSaveSlotName() {
	return SaveSlotName;
}

uint32 USettingsSaveGame::GetUserIndex() {
	return UserIndex;
}