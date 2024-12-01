// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_BatteryCheck.h"

class ABaseDummyCharacter;
enum class EBatteryStatus: uint8;

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
FBlackboardkeySelector IsBatteryDepleteKey;