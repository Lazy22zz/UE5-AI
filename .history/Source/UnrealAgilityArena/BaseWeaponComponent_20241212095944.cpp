// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeaponComponent.h"
#include "BaseDummyCharacter.h"

UBaseWeaponComponent::UBaseWeaponComponent()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(
        TEXT("/ Game/ KayKit/ PrototypeBits/ Models/ Gun_Pistol.Gun_ Pistol")
    );

    UstaticMeshComponent::SetStaticMesh(StaticMeshAsset.Object);
}

void UBaseWeaponComponent::Shoot()
{
    if(BulletClass == nullptr) return;
    auto const World = GetWorld();
    if (World == nullptr) return;
    const FRotator SpawnRotation = GetOwner() -> GetActorRotation();
    const FVector SpawnLocation = GetOwner() -> GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
    FActorSpawnParameters ActorSpawnParams;
    ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
    World-> SpawnActor<AActor>( BulletClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

}

void UBaseWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    const auto Character = Cast<ABaseDummyCharacter>(GetOwner());

    if (character == nullptr) return;
    AttachToComponent(Character -> GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "hand_right");
}
