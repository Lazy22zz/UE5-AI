// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "BaseWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, ClassGroup = "UnrealAgilityArena", meta = (BlueprintSpawnableComponent))
class UNREALAGILITYARENA_API UBaseWeaponComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UBaseWeaponComponent();

	UFUNCTION(BlueprintCallable)
	virtual void Shoot(); //spawn a bullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	TSubclassOf<AActor> BulletClass; // enable dynamic using class type

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	FVector MuzzleOffset = FVector(150, 30.f, 0.f); // place bullet spawn point

protected:
	virtual void BeginPlay() override;
};
