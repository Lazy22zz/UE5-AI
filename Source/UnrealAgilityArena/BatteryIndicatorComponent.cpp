// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryIndicatorComponent.h"
#include "BaseDummyCharacter.h"

UBatteryIndicatorComponent::UBatteryIndicatorComponent()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh>StaticMeshAsset(TEXT("/ Game/_GENERATED/ MarcoSecchi/ SM_HeadLight.SM_ Headlight"));
    if(StaticMeshAsset.Succeeded())
    {
        UStaticMeshComponent::SetStaticMesh(StaticMeshAsset.Object);
    }
}

void UBatteryIndicatorComponent::BeginPlay()
{
    Super::BeginPlay();
    ABaseDummyCharacter* Owner = Cast<ABaseDummyCharacter>(GetOwner());
    if(Owner == nullptr) return;
    AttachToComponent(Owner -> GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "helmet");
    DynamicMaterialInstance = this -> CreateDynamicMaterialInstance(1, GetMaterial(1));
    Owner -> OnBatteryStatusChanged.AddDynamic(this, &UBatteryIndicatorComponent::OnBatteryStatusChange);
}

void UBatteryIndicatorComponent::OnBatteryStatusChange(EBatteryStatus NewBatteryStatus)
{
	const auto BatteryValue = StaticCast<float>(NewBatteryStatus);

	const auto Intensity = (BatteryValue - 1.f) * 25.f;

	DynamicMaterialInstance->SetScalarParameterValue(FName("Intensity"), Intensity);
}