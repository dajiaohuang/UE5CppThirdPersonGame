#include "GA_Dash.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UGA_Dash::UGA_Dash()
{
    // 设置技能的基本属性
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    
    // 设置技能冷却
    FAbilityTriggerData TriggerData;
    TriggerData.TriggerTag = FGameplayTag::RequestGameplayTag(FName("Ability.Dash"));
    AbilityTriggers.Add(TriggerData);
}

void UGA_Dash::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
    if (!Character)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
    if (!MovementComponent)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    // 保存原始速度
    float OriginalSpeed = MovementComponent->MaxWalkSpeed;
    
    // 设置冲刺速度
    MovementComponent->MaxWalkSpeed = DashSpeed;

    // 创建定时器来恢复原始速度
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, MovementComponent, OriginalSpeed]()
    {
        if (MovementComponent)
        {
            MovementComponent->MaxWalkSpeed = OriginalSpeed;
        }
    }, DashDuration, false);

    // 应用冷却效果
    FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
    FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(CooldownGameplayEffect, 1, EffectContext);
    if (SpecHandle.IsValid())
    {
        FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
    }

    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
} 