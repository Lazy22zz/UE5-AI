// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGunBullet.h"
#include "GameFramework/ ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DamageEvents.h"


// Sets default values
ABaseGunBullet::ABaseGunBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called every frame
void ABaseGunBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

