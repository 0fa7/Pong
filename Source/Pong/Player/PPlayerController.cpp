// Fill out your copyright notice in the Description page of Project Settings.


#include "PPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PBatPawn.h"

void APPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(PongInputContext);
	
	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PongInputContext, 0);
	}
	
}

void APPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	Input->BindAction(MoveBatAction, ETriggerEvent::Triggered, this, &APPlayerController::MoveBatCallback);
	Input->BindAction(LaunchProjectileAction, ETriggerEvent::Triggered, this, &APPlayerController::LaunchProjectileCallback);
}

void APPlayerController::MoveBatCallback(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Display, TEXT("APPlayerController::MoveBatCallback()"));

	if(auto Bat = Cast<APBatPawn>(GetPawn()))
	{
		Bat->MoveBat(Value.Get<FVector>().X);
	}
}

void APPlayerController::LaunchProjectileCallback()
{
	UE_LOG(LogTemp, Display, TEXT("APPlayerController::LaunchProjectileCallback()"));

	if(auto Bat = Cast<APBatPawn>(GetPawn()))
	{
		Bat->Launch();
	}
}