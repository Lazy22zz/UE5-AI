// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecurityCamAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

const auto SenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight> ( "SenseConfig_Sight");
SenseConfig_Sight -> SightRadius = 1600.f;
SenseConfig_Sight -> LoseSightRadius = 3000.f;
SenseConfig_Sight -> PeripheralVisionAngleDegrees = 45.0f;
SenseConfig_Sight -> DetectionByAffiliation.bDetectEnemies = true;
SenseConfig_Sight -> DetectionByAffiliation.bDetectNetutrals = true;
SenseConfig_Sight -> DetectionByAffiliation.bDetectFriendlies = true;

PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
PerceptionComponent -> ConfigureSense(*SenseConfig_Sight);
PerceptionComponent -> SetDominantSense(SenseConfig_Sight_Sight -> GetSenseImplementation());
PerceptionComponent -> OnTargetPerceptionUpdated.AddDynamic(this, &ABaseSecurityCamAIController::OnTargetPerceptionUpdate);

void ABaseSecurityCamAIController::OnPossess(APawn *In Pawn)
{
    Super::OnPossess(InPawn);

}
