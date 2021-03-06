// Fill out your copyright notice in the Description page of Project Settings.



#include "TanKAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATanKAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI posses the %s"), *ControlledTank->GetName())
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("AI don`t posses tank"))
	}

	ATank* PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI point at %s"), *PlayerTank->GetName())
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("AI don`t found player tank"))
	}
}

ATank* ATanKAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerPawn) { return nullptr; }
	return Cast<ATank>(playerPawn);
}


ATank* ATanKAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



