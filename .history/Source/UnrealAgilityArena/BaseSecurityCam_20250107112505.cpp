// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecurityCam.h"

// Sets default values
ABaseSecurityCam::ABaseSecurityCam()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called to bind functionality to input
void ABaseSecurityCam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

