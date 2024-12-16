// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SetAmmo.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_SetAmmo::UBTService_SetAmmo()
{
    NodeName = "SetAmmo";
    bCreateNodeInstance = true;
    bNotifyBecomeRelevant = true;
    bNotifyTick = false;
}
