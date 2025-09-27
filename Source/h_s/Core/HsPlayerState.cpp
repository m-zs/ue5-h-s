// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsPlayerState.h"
#include "AbilitySystemComponent.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"
#include "h_s/GASP/Attributes/HsAttributeSet.h"

AHsPlayerState::AHsPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHsAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHsAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100);
}
