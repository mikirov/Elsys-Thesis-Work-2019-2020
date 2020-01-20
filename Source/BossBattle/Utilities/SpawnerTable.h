// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SpawnerTable.generated.h"


USTRUCT(BlueprintType, Meta=(DisplayName="SpawnerInfo"))
struct FSpawnerInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int EnemyCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AEnemyCharacter> EnemyAsset;
};

USTRUCT(BlueprintType, Meta=(DisplayName="SpawnerInfoArray"))
struct FSpawnerInfoArray {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<struct FSpawnerInfo> SpawnerInfoArray;
	
};



USTRUCT(BlueprintType)
struct FSpawnerTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FSpawnerTable()
		:
		SpawnerEnemyPlacement()
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	TArray<struct FSpawnerInfoArray> SpawnerEnemyPlacement;
};
