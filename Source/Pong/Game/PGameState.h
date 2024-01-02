// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PGameState.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API APGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	APGameState();

	UPROPERTY(EditAnywhere)
	int32 Player1Score = 0;

	UPROPERTY(EditAnywhere)
	int32 Player2Score = 0;

	UPROPERTY(EditAnywhere)
	float TimerCountdown = 0.f;
};
