// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::OnPossess(APawn* InPawn)
{
    UE_LOG(LogTemp, Log, TEXT("AMyPlayerController::OnPossess"));
    Super::OnPossess(InPawn);
    if(InPawn)
    {
        UE_LOG(LogTemp, Log, TEXT("InPawn: %s"), *InPawn->GetName());
        InPawn->SetActorLocation(FVector(0.0f, 0.0f, 100.0f));
    }
}


