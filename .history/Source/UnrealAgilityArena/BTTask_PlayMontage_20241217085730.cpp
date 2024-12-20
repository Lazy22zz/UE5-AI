// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PlayMontage.h"

EBTNodeResult::Type UBTTask_PlayMontage::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    if(AnimMontage == nullptr) return EBTNodeResult::Failed;
    const auto Controller = OwnerComp.GetAIOwner();

    if (Controller == nullptr) return EBTNodeResult::Failed;
    const auto Character = Cast<ACharacter> (Controller -> GetCharacter());

    if (Character == nullptr) return EBTNodeResult::Failed;
    Character -> PlayAnimMontage(AnimMontage, 1.f, FName("Default"));
    return EBTNodeResult::Succeeded;
}
