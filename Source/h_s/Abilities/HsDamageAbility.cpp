// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsDamageAbility.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"
#include "h_s/Character/AsCharacter.h"

void UHsDamageAbility::DoDamage(AAsCharacter* Initiator, AAsCharacter* Target) const
{
	FGameplayEffectContextHandle EffectContextHandle = Initiator->GetAbilitySystemComponent()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(Initiator->GetAbilitySystemComponent()->GetAvatarActor());
	
	const FGameplayEffectSpecHandle SpecHandle = Initiator->GetAbilitySystemComponent()->MakeOutgoingSpec(DamageEffect, 1, EffectContextHandle);
	
	Target->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
}

void UHsDamageAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	AbilityActorInfo = ActorInfo;

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}