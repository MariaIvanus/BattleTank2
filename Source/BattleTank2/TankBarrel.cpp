// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankBarrel::Elevate(float  RelativeSpeed)
{
	
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel elevator called "), Time)
	//Move the barrel the right amount this frame
	//Given a max elevation speed and the frame time
}

