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
