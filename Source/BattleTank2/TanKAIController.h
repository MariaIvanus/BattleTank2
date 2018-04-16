// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TanKAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK2_API ATanKAIController : public AAIController
{
	GENERATED_BODY()

	ATank* GetPlayerTank() const;
	ATank* GetControlledTank() const;

protected:
	virtual void BeginPlay() override;
	
	
};
