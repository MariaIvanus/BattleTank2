// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerConproller.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankPlayerConproller::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player posses %s tank"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player do not posses the tank"));
	}
}

void ATankPlayerConproller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tick"));

	AimTowardCrosshair();
}



ATank* ATankPlayerConproller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerConproller::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;//OUT parameter;

	if (GetSightRayHitLocation(HitLocation)) //has side-effect, is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}

}

//chaeck what returns... and ifs
bool ATankPlayerConproller::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewportSizeX, CrossHairYLocation*ViewportSizeY);

	FVector LookDirection;
	//De-project the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line trace
		GetLookVectorHitLocation(LookDirection, HitLocation);
		return true; // TODO not sure what is it...
	}
	return false;
}

bool ATankPlayerConproller::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	} 
	else
	{
		HitLocation = FVector(0);
		return false; // if line trace didn`t hit anything;
	}

}

bool ATankPlayerConproller::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // noise to make method work

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}
