// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PBatPawn.generated.h"

class UStaticMeshComponent;
class UCameraComponent;
class UBoxComponent;
class APProjectile;

UCLASS()
class PONG_API APBatPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APBatPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveBat(float Direction);

	void SpawnProjectile(bool bSpawnOnRightSide);

	void Launch();

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> GameCamera;

	UPROPERTY(EditAnywhere)
	FVector WorldCameraLocation = {0.f, 0.f,0.f};
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BatMesh;
	
	UPROPERTY(EditAnywhere)
	FVector RelativeBatScale = {.1f, .1f, 1.f};
	
	UPROPERTY(EditAnywhere)
	FVector RelativeBatLocation = {0.f, 0.f,-50.f};
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> ProjectileSpawnLocation1;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> ProjectileSpawnLocation2;

	UPROPERTY(EditAnywhere)
	float ProjectileSpawnOffset = 300.f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APProjectile> ProjectileClass;
	
	UPROPERTY(EditAnywhere)
	FVector SpawnOffset1;

	UPROPERTY(EditAnywhere)
	FVector SpawnOffset2;

	UPROPERTY(EditAnywhere)
	float BatSpeed = 100.f;

	TObjectPtr<APProjectile> CurrentProjectile;
};
