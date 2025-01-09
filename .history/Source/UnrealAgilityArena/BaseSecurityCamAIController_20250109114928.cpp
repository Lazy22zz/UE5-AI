// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecurityCamAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ABaseSecurityCamAIController::ABaseSecurityCamAIController()
{
	// Create and configure the sight sense configuration
	const auto SenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("SenseConfig_Sight");
	SenseConfig_Sight->SightRadius = 2000.f; // Set the sight radius
	SenseConfig_Sight->LoseSightRadius = 2500.f; // Set the lose sight radius
	SenseConfig_Sight->PeripheralVisionAngleDegrees = 45.0f; // Set the peripheral vision angle
	SenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true; // Enable detection of enemies
	SenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = true; // Enable detection of neutrals
	SenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = true; // Enable detection of friendly units

	// Create and configure the perception component
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	PerceptionComponent->ConfigureSense(*SenseConfig_Sight); // Configure the perception component with the sight sense
	PerceptionComponent->SetDominantSense(SenseConfig_Sight->GetSenseImplementation()); // Set the dominant sense as the sight sense
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseSecurityCamAIController::OnTargetPerceptionUpdate); // Add the OnTargetPerceptionUpdate event handler
}

void ABaseSecurityCamAIController::OnPossess(APawn *InPawn)
{
    Super::OnPossess(InPawn);
    if (ensureMsgf( BehaviorTree, 
        TEXT(" Behavior Tree is nullptr! Please assign BehaviorTree in your AI Controller.") )
       ) 
    { 
        RunBehaviorTree(BehaviorTree);
    }

}

void ABaseSecurityCamAIController::OnTargetPerceptionUpdate(AActor *Actor, FAIStimulus Stimulus)
{
    if (Actor -> Tags.Num() > 0) return;
    const auto SightID = UAISense::GetSenseID<UAISense_Sight>();
    if (Stimulus.Type == SightID && Stimulus.WasSuccessfullySensed())
    {
        Actor -> Tags.Init({}, 1);
        Actor -> Tags[0] = "ShootingTarget";
    }
}
