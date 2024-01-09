// Fill out your copyright notice in the Description page of Project Settings.


#include "PProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
APProjectile::APProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Projectile Mesh");
	ProjectileMesh->SetRelativeScale3D(RelativeProjectileScale);
	RootComponent = ProjectileMesh;

	
	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Comp");
	ProjectileComp->Bounciness = 100.f;
	ProjectileComp->bShouldBounce = true;
	ProjectileComp->Friction = 0.f;
	ProjectileComp->ProjectileGravityScale = 0.f;
	ProjectileComp->MaxSpeed = MaxSpeed;
	
}

// Called when the game starts or when spawned
void APProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

