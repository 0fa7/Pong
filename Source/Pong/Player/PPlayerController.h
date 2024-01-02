// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class PONG_API APPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> PongInputContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveBatAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> LaunchProjectileAction;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void MoveBatCallback();
	void LaunchProjectileCallback();
};
