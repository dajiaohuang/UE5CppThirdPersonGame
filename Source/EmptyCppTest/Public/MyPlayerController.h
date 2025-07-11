// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * Player() -> OnPossess() -> beginplay()
 * 
 * HUD
 */
UCLASS()
class EMPTYCPPTEST_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	virtual void OnPossess(APawn* InPawn) override;
};
