// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BOSSBATTLE_API FCustomUtilities
{
public:
	// 0 to 360 rotation to -180 to 180 rotation.
	static FRotator GetStandardUnrealRotation(FRotator Rotation);

	static float NormalizeFloatAsRotationValue(float Value);
};
