// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTarget.h"

// Sets default values
ABaseTarget::ABaseTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent -> SetupAttachment(RootComponent);
	MeshComponent -> SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	RootComponent = MeshComponent;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshAsset(
		TEXT("/ Game/ KayKit/ PrototypeBits/ Models/ target_stand_B_target_ stand_B.target_stand_B_target_stand_B");
	)
	if(StaticMeshAsset.Succeeded())
	{
		MeshComponent -> SetStaticMesh(StaticMeshAsset.Object);
	}

}

float ABaseTarget::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
    Tags[0] = "Untagged"; //invalidate the tag assigned to the parent object.
	return DamageAmount;
}
