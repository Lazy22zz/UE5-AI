// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SpeedControl.h"
#include "BaseDummyAIController.h"
#include "BaseDummyCharacter.h"

void UBTService_SpeedControl::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    const auto AIController = Cast<ABaseDummyAIController>(OwnerComp.GetAIOwner());
    if(!AIController) return;

    const auto ControlledCharacter = Cast<ABaseDummyCharacter>(AIController -> GetPawn());
    if (!ControlledCharacter) return;

    switch(ControlledCharacter -> GetBatteryStatus())
    {
        case EBatteryStatus::EBS_Empty:
        break;
        case EBatteryStatus::EBS_Low:
        ControlledCharacter -> SetWalkSpeed();
        break;
        case EBatteryStatus::EBS_Medium:
        case EBatteryStatus::EBS_Full:
        ControlledCharacter -> SetRunSpeed();
        break;
    }
}
