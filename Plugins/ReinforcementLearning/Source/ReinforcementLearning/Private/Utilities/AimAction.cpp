// Fill out your copyright notice in the Description page of Project Settings.


#include "AimAction.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "CustomMacros.h"
#include "GameFramework/Character.h"
#include <limits>
#include "Kismet/KismetMathLibrary.h"

UAimAction::UAimAction()
{

}

bool UAimAction::Execute_Implementation()
{

	if (validate(IsValid(Pawn)) == false) return false;

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return false;

	APawn* ChosenPawn = nullptr;
	float CurrentDistance = std::numeric_limits<float>::max();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(World, ACharacter::StaticClass(), Actors);
	
	for (AActor* Actor : Actors) {
		APawn* CurrentPawn = Cast<APawn>(Actor);
		if (validate(IsValid(CurrentPawn)) == false) { continue; }

		float DistanceToPlayer = FVector::Dist(CurrentPawn->GetActorLocation(), Pawn->GetActorLocation());
		if (DistanceToPlayer < CurrentDistance) {
			ChosenPawn = CurrentPawn;
			CurrentDistance = DistanceToPlayer;
		}
	}

	if (validate(IsValid(ChosenPawn) == false)) return false;

	AController* Controller = GetPawn()->GetController();

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		GetPawn()->GetActorLocation(),
		ChosenPawn->GetActorLocation()
	);

	Pawn->SetActorRotation(FRotator(0, LookAtRotation.Yaw, 0));

	Controller->SetControlRotation(FRotator(0, LookAtRotation.Yaw, 0));
	return true;
}
