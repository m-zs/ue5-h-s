// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.


#include "HsDamageAbility.h"

void UHsDamageAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	AbilityActorInfo = ActorInfo;
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}