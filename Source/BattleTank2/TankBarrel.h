// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK2_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 - ax down speed, +1 max up speed
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegresPerSec = 20.0;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 40.0;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDergree = 0;
	
};
