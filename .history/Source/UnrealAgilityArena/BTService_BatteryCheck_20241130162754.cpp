// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_BatteryCheck.h"

UBTService_BatteryCheck::UBTService_BatteryCheck()
{
    bCreateNodeInstance = true;
    bNotifyBecomeRelevant = true;
    bNotifyCeaseRelevant = true;
    bNotifyTick = false;
}
