// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_BatteryCheck.h"

class ABaseDummyCharacter;
enum class EBatteryStatus: uint8;

public: 
UBTService_BatteryCheck();

protected:
UPROPERTY()
UBlackboardComponent* BlackboardComponent = nullptr;
