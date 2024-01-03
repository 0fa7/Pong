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
	
	ProjectileSpawnPlayer1 = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Player 1");
	ProjectileSpawnPlayer1->SetupAttachment(BatMesh);
	SpawnLocation1 = -1.f * RelativeBatLocation;
	SpawnLocation1.Y += ProjectileSpawnOffset;
	ProjectileSpawnPlayer1->SetRelativeLocation(SpawnLocation1);
	
	ProjectileSpawnPlayer2 = CreateDefaultSubobject<USceneComponent>("Projectile Spawn Player 2");
	ProjectileSpawnPlayer2->SetupAttachment(BatMesh);
	SpawnLocation2 = -1.f * RelativeBatLocation;
	SpawnLocation2.Y -= ProjectileSpawnOffset;
	ProjectileSpawnPlayer2->SetRelativeLocation(SpawnLocation2);
	
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
		UE_LOG(LogTemp, Display, TEXT("APBatPawn::SpawnProjectile(bool bSpawnOnRightSide)"));
		auto Projectile = GetWorld()->SpawnActor<APProjectile>(ProjectileClass, SpawnLocation1, FRotator::ZeroRotator);
		//this->AttachToComponent()
	}
	else
	{
		
	}
}
