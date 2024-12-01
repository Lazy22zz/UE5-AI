// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_BatteryCheck.h"
#include "BaseDummyCharacter.h"
#include "BatteryStatus.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_BatteryCheck::UBTService_BatteryCheck()
{
    bCreateNodeInstance = true;
    bNotifyBecomeRelevant = true;
    bNotifyCeaseRelevant = true;
    bNotifyTick = false;
}

void UBTService_BatteryCheck::OnBecomeRelevant(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    switch(NewBatteryStatus)
    {
        case EBatteryStatus::EBS_Empty:
        BlackboardComponent -> SetValueAsBool(IsBatteryDepletedKey.SelectedKeyName, true);
        break;
        case EBatteryStatus::EBS_Low:
        BlackboardComponent -> SetValueAsBool(IsLowBatteryKey.SelectedKeyName, true);
        BlackboardComponent -> SetValueAsBool(IsBatteryDepletedKey.SelectedKeyName, false);
        break;
        case EBatteryStatus::EBS_Medium:
        break;
        case EBatteryStatus::EBS_Full:
        BlackboardComponent -> SetValueAsBool(IsLowBatteryKey.SelectedKeyName, false);
        break;
    }
}
