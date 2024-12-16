// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_CheckTagOnActor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

// Constructor: Sets up initial configuration for the decorator
UBTDecorator_CheckTagOnActor::UBTDecorator_CheckTagOnActor()
{
    // Set the name of the node as it will appear in the Behavior Tree editor
    NodeName = "Tag Condition";

    // Configure the Blackboard key selector (ActorToCheck) to only accept AActor objects
    ActorToCheck.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTDecorator_CheckTagOnActor, ActorToCheck), AActor::StaticClass());

    // Set the default Blackboard key to "KeySelf," referring to the AI itself
    ActorToCheck.SelectedKeyName = FBlackboard::KeySelf;
}

// Evaluates the condition to determine whether the decorator's branch should execute
bool UBTDecorator_CheckTagOnActor::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const
{
    // Get the Blackboard Component from the Behavior Tree's owner
    const UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp == nullptr) return false; // Return false if no Blackboard is found

    // Retrieve the actor stored in the Blackboard key specified by ActorToCheck
    const AActor* Actor = Cast<AActor>(BlackboardComp->GetValue<UBlackboardKeyType_Object>(ActorToCheck.SelectedKeyName));

    // Check if the actor exists and has the specified tag (TagName)
    return Actor != nullptr && Actor->ActorHasTag(TagName);
}

// Initializes the decorator from the associated Behavior Tree asset
void UBTDecorator_CheckTagOnActor::InitializeFromAsset(UBehaviorTree &Asset)
{
    // Call the parent class's InitializeFromAsset to handle default setup
    Super::InitializeFromAsset(Asset);

    // Retrieve the Blackboard asset from the Behavior Tree
    if (const UBlackboardData* BBAsset = GetBlackboardAsset(); ensure(BBAsset))
    {
        // Resolve the selected key (ActorToCheck) against the Blackboard asset to ensure it matches
        ActorToCheck.ResolveSelectedKey(*BBAsset);
    }
}
