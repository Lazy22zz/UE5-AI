// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseDummyAIController.generated.h"

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API ABaseDummyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Dummy AI Controller")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	virtual void OnPossess(APawn* InPawn) override;
	
};
