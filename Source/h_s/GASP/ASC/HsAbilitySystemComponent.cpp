// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsAbilitySystemComponent.h"

void UHsAbilitySystemComponent::AddAbilities(const TArray<TSubclassOf<UGameplayAbility>>& Abilities)
{
	for (const auto Ability : Abilities)
	{
		if (Ability == nullptr) continue;
		FGameplayAbilitySpec Spec = FGameplayAbilitySpec(Ability, 1);
		if (const auto AbilitySpec = Spec.Ability; IsValid(AbilitySpec))
		{
			GiveAbility(Spec);
		}
	}
}
