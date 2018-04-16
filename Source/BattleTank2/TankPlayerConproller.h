// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerConproller.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK2_API ATankPlayerConproller : public APlayerController
{
	GENERATED_BODY()

	ATank* GetControlledTank() const;

	//start tank moving barrel so that a shot would it where the crosshair intersects
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.251;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000; // distance in santimetres(units);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
