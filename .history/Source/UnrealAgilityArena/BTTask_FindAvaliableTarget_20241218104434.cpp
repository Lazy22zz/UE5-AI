// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindAvaliableTarget.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindAvaliableTarget::UBTTask_FindAvaliableTarget()
{
    NodeName = "Find Available Target";
    TargetActor.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindAvaliableTarget, TargetActor), AActor::StaticClass());
    TargetActor.SelectedKeyName = FBlackboard::KeySelf;
}

EBTNodeResult::Type UBTTask_FindAvaliableTarget::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    const auto BlackboardComp = OwnerComp.GetBlackboardComponent();

    if(BlackboardComp == nullptr) {return EBTNodeResult::Failed;}
    TArray<AActor*> TargetList;

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), TargetTag, TargetList);

    if(TargetList.Num() == 0) {return EBTNodeResult::Failed;}
    const auto RandomTarget = TargetList[FMath::RandRange(0, TargetList.Num() - 1)];

    BlackboardComp -> SetValueAsObject(TargetActor.SelectedKeyName, RandomTarget);
    return EBTNodeResult::Succeeded;
}
