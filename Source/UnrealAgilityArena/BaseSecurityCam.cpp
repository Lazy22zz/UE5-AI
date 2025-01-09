// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecurityCam.h"

// Sets default values
ABaseSecurityCam::ABaseSecurityCam()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SupportMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Support Mesh"));
	RootComponent = SupportMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SupportStaticMeshAsset(
		TEXT("/ Game/_GENERATED/ MarcoSecchi/ SM_SecurityCam_Base.SM_SecurityCam_Base")
	);

	if (SupportStaticMeshAsset.Succeeded())
	{
		SupportMeshComponent -> SetStaticMesh(SupportStaticMeshAsset.Object);
	}
	CamMeshComponent = CreateDefaultSubobject <UStaticMeshComponent> (TEXT("Cam Mesh"));
	CamMeshComponent -> SetRelativeLocation(FVector(61.f, 0.f, -13.f));
	CamMeshComponent -> SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CamStaticMeshAsset(
		TEXT("/ Game/_GENERATED/ MarcoSecchi/ SM_SecurityCam.SM_SecurityCam")
	);

	if (CamStaticMeshAsset.Succeeded())
	{
		CamMeshComponent -> SetStaticMesh(CamStaticMeshAsset.Object);
	}

}

// Called to bind functionality to input
void ABaseSecurityCam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

