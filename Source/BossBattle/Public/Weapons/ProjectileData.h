
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ProjectileData.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FProjectileData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()



	//particle system to emit on impact
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UParticleSystem* HitParticleSystem = nullptr;

	//sound to be played on ground hit
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TAssetPtr<class USoundCue> HitGroundSound;

	//sound to be played on enemy hit
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TAssetPtr<class USoundCue> HitEnemySound;

	//Damage to deal on hit
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Damage;

	//time after which the projectile gets destroye (in seconds)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float SelfDestroyTime;

	//List of tags to ignore on hit
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<FName> TagsToIgnore;

};