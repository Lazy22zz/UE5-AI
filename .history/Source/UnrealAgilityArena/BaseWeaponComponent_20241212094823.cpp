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
}

void UBaseWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    const auto Character = Cast<ABaseDummyCharacter>(GetOwner());

    if (character == nullptr) return;
    AttachToComponent(Character -> GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "hand_right");
}
