// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API APGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	APGameMode();

	void SpawnProjectile();

	int32 LastPlayerToScore = 0;

	bool bIsProjectileInPlay = false;
};
