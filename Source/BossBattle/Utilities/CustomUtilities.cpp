// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomUtilities.h"

FRotator FCustomUtilities::GetStandardUnrealRotation(FRotator Rotation) {
	Rotation.Yaw = NormalizeFloatAsRotationValue(Rotation.Yaw);
	Rotation.Pitch = NormalizeFloatAsRotationValue(Rotation.Pitch);
	Rotation.Roll = NormalizeFloatAsRotationValue(Rotation.Roll);

	return Rotation;
}



float FCustomUtilities::NormalizeFloatAsRotationValue(float Value) {
	if (Value > 180) {
		Value -= 360;
	}
	else if (Value < -180)
	{
		Value += 360;
	}
	return Value;
}