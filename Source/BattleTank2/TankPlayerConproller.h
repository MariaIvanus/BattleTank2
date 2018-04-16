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

	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.251;

};
