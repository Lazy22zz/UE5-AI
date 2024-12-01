// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_BatteryChedck.generated.h"

class ABaseDummyCharacter;
enum class EBatteryStatus: uint8;
/**
 * 
 */
UCLASS()
class UNREALAGILITYARENA_API UBTService_BatteryChedck : public UBTService
{
	GENERATED_BODY()

public: 
	UBTService_BatteryCheck();

protected:
	UPROPERTY()
	UBlackboardComponent* BlackboardComponent = nullptr;

	UPROPERTY()
	ABaseDummyCharacter* ControlledCharacter = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FBlackboardkeySelector IsLowOnBatteryKey;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Blackboard")
	FBlackboardkeySelector IsBatteryDepletedKey;	
};
