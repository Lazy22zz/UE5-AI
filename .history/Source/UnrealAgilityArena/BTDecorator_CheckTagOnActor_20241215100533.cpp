// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CheckTagOnActor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UBTDecorator_CheckTagOnActor::UBTDecorator_CheckTagOnActor()
{
    NodeName = "Tag Condition";
    ActorToCheck.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTDecorator_CheckTagOnActor, ActorToCheck), AActor::StaticClass());
    ActorToCheck.SelectedKeyName = FBlackboard::KeySelf;
}
