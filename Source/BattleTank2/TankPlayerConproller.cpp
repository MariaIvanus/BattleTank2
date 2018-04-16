// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerConproller.h"

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

	UE_LOG(LogTemp, Warning, TEXT("Tick"));

	AimTowardCrosshair();
}



ATank* ATankPlayerConproller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerConproller::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{

	}

}

bool ATankPlayerConproller::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewportSizeX, CrossHairYLocation*ViewportSizeY);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), * ScreenLocation.ToString())
	return false;
}
