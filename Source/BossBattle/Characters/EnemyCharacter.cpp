// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

void AEnemyCharacter::Reset() {

}

void AEnemyCharacter::IncrementKillScore() {
	Kills += 1;
}

int AEnemyCharacter::GetKills() const {
	return Kills;
}
