// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Shoot.h"
#include "BaseDummyCharacter.h"
#include "BaseWeaponComponent.h"

UAnimNotify_Shoot::UAnimNotify_Shoot():Super()
{
#if WITH_EDITORONLY_DATA
    NotifyColor = FColor(222, 142, 142, 255);
#endif
}

void UAnimNotify_Shoot::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, const FAnimNotifyEventReference &EventReference)
{
    if(MeshComp == nullptr) return;
    const auto Character = Cast<ABaseDummyCharacter>(MeshComp -> GetOwner());

    if(Character == nullptr) return;
    const auto WeaponComponent = Character -> GetComponentByClass<UBaseWeaponComponent>();

    if(WeaponComponent == nullptr) return;
    WeaponComponent -> Shoot();
}
