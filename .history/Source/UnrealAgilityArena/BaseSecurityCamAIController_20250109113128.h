// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseSecurityCamAIController.generated.h"

struct FAIStimulus;
struct FActorPerceptionUpdateInfo;
class UBehaviorTree;

/**
 * 
 */
UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseSecurityCamAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dummy AI Controller")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	virtual void OnPossess(APawn* In Pawn) override;

	UFUNCTION()
	void OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);
};
