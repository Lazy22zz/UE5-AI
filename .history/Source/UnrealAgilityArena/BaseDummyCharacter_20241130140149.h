// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BatteryStatus.h"
#include "BaseDummyCharacter.generated.h"

UCLASS()
class UNREALAGILITYARENA_API ABaseDummyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseDummyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	float BatteryLevel;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Dummy Character")
	void SetWalkSpeed();

	UFUNCTION(BlueprintCallable, Category = "Dummy Character")
	void SetRunSpeed();

	UFUNCTION(BlueprintCallable, BlueprintGetter, Category = "Dummy Character")
	EBatteryStatus GetBatteryStatus() const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dummy Character")
	float MaxBatteryLevel = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dummy Character")
	float BatteryCostPerTick = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dummy Character")
	float BatteryRechargePerTick = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dummy Character")
	float RunSpeed = 650.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dummy Character")
	float WalkSpeed = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dummy Character")
	float MovementRandomDeviation = 5.f;

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBatteryStatusChanged, EBatteryStatus, NewBatteryStatus);

    UPROPERTY(BlueprintAssignable, Category = "Dummy Character")
    FOnBatteryStatusChanged OnBatteryStatusChanged;

};
