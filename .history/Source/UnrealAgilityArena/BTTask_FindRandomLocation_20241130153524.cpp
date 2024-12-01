// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandomLocation.h"

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    const auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    // retrieve all actors in the level
    TArray<AActor*> TargetList;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), TargetTag, TargetList);
    if(TargetList.Num() == 0)
    {
        return EBTNodeResult::Failed;
    }

    const auto RandomTarget = TargetList[FMath::RandRange(0, TargetList.Num() - 1)];
    BlackboardComp -> SetValueAsVector(BlackboardKey.SelectedKeyName, RandomTarget -> GetActorLocation());
    return EBTNodeResult::Succeeded;
}
