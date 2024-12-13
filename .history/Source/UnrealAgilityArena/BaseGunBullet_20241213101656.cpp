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
	InitialLifeSpan = 10.0f;
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionComponent -> InitSphereRadius(20.0f);
	CollisionComponent -> BodyInstance.SetCollisionProfileName("BlockAll");
	CollisionComponent -> OnComponentHit.AddDynamic(this, &ABaseGunBullet::OnHit);
	CollisionComponent -> SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComponent -> CanCharacterStepUpOn = ECB_No;
	RootComponent = CollisionComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	ProjectileMovementComponent -> UpdatedComponent = CollisionComponent;
	ProjectileMovementComponent -> InitialSpeed = 1800.f;
	ProjectileMovementComponent -> MaxSpeed = 1800.f;
	ProjectileMovementComponent -> bRotationFollowsVelocity = true;
	ProjectileMovementComponent -> ProjectileGravityScale = 0.f;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent -> SetupAttachment(RootComponent);
	MeshComponent -> SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	MeshComponent -> SetRelativeScale3D(FVector(2.f, 2.f, 2.f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshAsset(
		TEXT("/Game/KayKit/PrototypeBits/Models/Bullet.Bullet")
	);
	if (StaticMeshAsset.Succeeded())
	{
		MeshComponent -> SetStaticMesh(StaticMeshAsset.Object);
	}
}

// Called every frame
void ABaseGunBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGunBullet::OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	if (OtherActor != nullptr && OtherActor != this)
	{
		const auto DamageEvt = FDamageEvent();
		OtherActor -> TakeDamage(1.f, DamageEvt, nullptr, nullptr);
	}
	Destory();
}
