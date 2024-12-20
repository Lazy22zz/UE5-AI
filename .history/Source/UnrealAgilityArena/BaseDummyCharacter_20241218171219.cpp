// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDummyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BatteryStatus.h"

// Sets default values
ABaseDummyCharacter::ABaseDummyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = .25f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetMesh() -> SetRelativeLocation(FVector(0.f, 0.f, -120.f));
	GetMesh() -> SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeletalMeshAsset(TEXT("/Game/KayKit/PrototypeBits/Character/Dummy.Dummy"));
	if (SkeletalMeshAsset.Succeeded())
	{
		GetMesh() -> SetSkeletalMesh(SkeletalMeshAsset.Object);
	}
	GetMesh() -> SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers:: FObjectFinder < UAnimBlueprint > AnimBlueprintAsset( TEXT("/Game/KayKit/PrototypeBits/Character/ABP_Dummy.ABP_Dummy"));
	if (AnimBlueprintAsset.Succeeded())
	{
		GetMesh() -> SetAnimClass(AnimBlueprintAsset.Object -> GeneratedClass);
	}

	GetCapsuleComponent() -> InitCapsuleSize(50.f, 120.0f);
	GetCharacterMovement() -> bOrientRotationToMovement = true;
	GetCharacterMovement() -> MaxWalkSpeed = 500.f;
	GetCharacterMovement() -> RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement() -> bConstrainToPlane = true;
	GetCharacterMovement() -> bSnapToPlaneAtStart = true;
	GetCharacterMovement() -> AvoidanceConsiderationRadius = 2000.f;
	GetCharacterMovement() -> bUseRVOAvoidance = true;
}

// Called when the game starts or when spawned
void ABaseDummyCharacter::BeginPlay()
{
	Super::BeginPlay();

	BatteryLevel = MaxBatteryLevel * FMath::RandRange(0.f, 1.f);
	OnBatteryStatusChanged.Broadcast(GetBatteryStatus());
	
}

// Called every frame
void ABaseDummyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto CurrentStatus = GetBatteryStatus();
	if(GetMovementComponent() -> Velocity.Size() > .1f)
	{
		BatteryLevel -= BatteryCostPerTick;
	}
	else
	{
		BatteryLevel += BatteryRechargePerTick;
	}
	BatteryLevel = FMath::Clamp<float>(BatteryLevel, 0.f, MaxBatteryLevel);
	if (const auto NewStatus = GetBatteryStatus(); CurrentStatus != NewStatus)
	{
		OnBatteryStatusChanged.Broadcast(NewStatus);
	} 

}

void ABaseDummyCharacter::SetWalkSpeed()
{
	const auto Deviation = FMath::RandRange(-1.f * MovementRandomDeviation, MovementRandomDeviation);
	GetCharacterMovement() -> MaxWalkSpeed = WalkSpeed + Deviation;
}

void ABaseDummyCharacter::SetRunSpeed()
{
	const auto Deviation = FMath::RandRange(-1.f * MovementRandomDeviation, MovementRandomDeviation);
	GetCharacterMovement() -> MaxWalkSpeed = RunSpeed + MovementRandomDeviation;
}

EBatteryStatus ABaseDummyCharacter::GetBatteryStatus() const
{
	const auto Value = BatteryLevel / MaxBatteryLevel;
	if (Value < 0.05f)
	{
		return EBatteryStatus::EBS_Empty;
	}
	if (Value < 0.35f)
	{
		return EBatteryStatus::EBS_Low;
	}
	if (Value < 0.95f)
	{
		return EBatteryStatus::EBS_Medium;
	}
	return EBatteryStatus::EBS_Full;
}

