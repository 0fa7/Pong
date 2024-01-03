// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PProjectile.generated.h"

UCLASS()
class PONG_API APProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> ProjectileMesh;

	UPROPERTY(EditAnywhere)
	FVector RelativeProjectileScale = {1.f, 1.f, 1.f};
};
