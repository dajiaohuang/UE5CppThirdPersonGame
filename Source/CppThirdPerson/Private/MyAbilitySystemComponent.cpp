#include "MyAbilitySystemComponent.h"

UMyAbilitySystemComponent::UMyAbilitySystemComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UMyAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
    Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
} 