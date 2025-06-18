// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"


void AWarrior::Attack()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Warrior Attack"));
}
