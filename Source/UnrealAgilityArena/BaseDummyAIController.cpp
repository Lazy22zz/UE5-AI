// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDummyAIController.h"

void ABaseDummyAIController::OnPossess(APawn *InPawn)
{
    Super::OnPossess(InPawn);
    if(ensureMsgf(BehaviorTree, TEXT("Behavior Tree is nullptr! Please assign BehaviorTree in your AI Controller.")))
    {
        RunBehaviorTree(BehaviorTree);
    }
}
