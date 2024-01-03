// Fill out your copyright notice in the Description page of Project Settings.


#include "PBatPawn.h"

#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Pong/Projectile/PProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Pong/Game/PGameMode.h"

// Sets default values
APBatPawn::APBatPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GameCamera = CreateDefaultSubobject<UCameraComponent>("Game Camera");
	GameCamera->SetWorldLocation(WorldCameraLocation);
	RootComponent = GameCamera;

	BatMesh = CreateDefaultSubobject<UStaticMeshComponent>("Bat Mesh");
	BatMesh->SetRelativeScale3D(RelativeBatScale);
	BatMesh->SetRelativeLocation(RelativeBatLocation);
	BatMesh->SetSimulatePhysics(false);
	BatMesh->SetGenerateOverlapEvents(true);
	BatMesh->SetupAttachment(RootComponent);
	
	ProjectileSpawnLocation1 = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Player 1");
	ProjectileSpawnLocation1->SetupAttachment(BatMesh);
	SpawnOffset1 = -1.f * RelativeBatLocation;
	SpawnOffset1.Y += ProjectileSpawnOffset;
	ProjectileSpawnLocation1->SetRelativeLocation(SpawnOffset1);
	
	ProjectileSpawnLocation2 = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Player 2");
	ProjectileSpawnLocation2->SetupAttachment(BatMesh);
	SpawnOffset2 = -1.f * RelativeBatLocation;
	SpawnOffset2.Y -= ProjectileSpawnOffset;
	ProjectileSpawnLocation2->SetRelativeLocation(SpawnOffset2);
	
}

// Called when the game starts or when spawned
void APBatPawn::BeginPlay()
{
	Super::BeginPlay();
	auto GameMode = Cast<APGameMode>(UGameplayStatics::GetGameMode(this));
	GameMode->SpawnProjectile();
}

// Called every frame
void APBatPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APBatPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APBatPawn::MoveBat(float Direction)
{
	BatMesh->AddRelativeLocation(FVector(0.f,0.f,Direction * BatSpeed * GetWorld()->GetDeltaSeconds()), true);
}

void APBatPawn::SpawnProjectile(bool bSpawnOnRightSide)
{
	if(bSpawnOnRightSide == true)
	{
		auto Projectile = GetWorld()->SpawnActor<APProjectile>(ProjectileClass, ProjectileSpawnLocation1->GetComponentLocation(), FRotator::ZeroRotator);
	}
	else
	{
		auto Projectile = GetWorld()->SpawnActor<APProjectile>(ProjectileClass, ProjectileSpawnLocation2->GetComponentLocation(), FRotator::ZeroRotator);
	}
}
