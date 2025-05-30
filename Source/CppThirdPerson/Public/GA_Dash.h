#pragma once

#include "CoreMinimal.h"
#include "MyGameplayAbility.h"
#include "GA_Dash.generated.h"

UCLASS()
class CPPTHIRDPERSON_API UGA_Dash : public UMyGameplayAbility
{
    GENERATED_BODY()

public:
    UGA_Dash();

    // 冲刺速度
    UPROPERTY(EditDefaultsOnly, Category = "Dash")
    float DashSpeed = 1000.0f;

    // 冲刺持续时间
    UPROPERTY(EditDefaultsOnly, Category = "Dash")
    float DashDuration = 0.2f;

    // 技能冷却时间
    UPROPERTY(EditDefaultsOnly, Category = "Dash")
    float CooldownDuration = 1.0f;

protected:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
}; 