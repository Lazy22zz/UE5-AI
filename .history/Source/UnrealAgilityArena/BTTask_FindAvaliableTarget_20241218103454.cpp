// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindAvaliableTarget.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindAvaliableTarget::UBTTask_FindAvaliableTarget()
{
    NodeName = "Find Available Target";
    TargetActor.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTASK_FindAvaliableTarget, TargetActor), AActor::StaticClass());
    TargetActor.SelectedKeyName = FBlackboard::KeySelf;
}
