// Fill out your copyright notice in the Description page of Project Settings.


#include "PGameMode.h"

#include "Pong/Projectile/PProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Pong/Player/PBatPawn.h"

APGameMode::APGameMode() : Super()
{
	
}

void APGameMode::SpawnProjectile()
{
	
	if(bIsProjectileInPlay == true)
	{
		return;
	}
	
	auto BatPawn = Cast<APBatPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if(LastPlayerToScore == 0 || LastPlayerToScore == 1)
	{
		BatPawn->SpawnProjectile(true);
	}
	else
	{
		BatPawn->SpawnProjectile(false);
	}

	bIsProjectileInPlay = true;
}
