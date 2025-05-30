#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MyAbilitySystemComponent.generated.h"

UCLASS()
class CPPTHIRDPERSON_API UMyAbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

public:
    UMyAbilitySystemComponent();

    // 初始化能力系统
    virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;
}; 