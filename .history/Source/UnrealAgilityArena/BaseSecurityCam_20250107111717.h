// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseSecurityCam.generated.h"

class UAIPerceptionComponent;

UCLASS(Blueprintable)
class UNREALAGILITYARENA_API ABaseSecurityCam : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseSecurityCam();

protected:

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
