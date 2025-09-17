// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsAttributeSet.h"
#include "Net/UnrealNetwork.h"

UHsAttributeSet::UHsAttributeSet() {}

void UHsAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
}

void UHsAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, CurrentHealth, OldCurrentHealth);
}

void UHsAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, MaxHealth, OldMaxHealth);
}

void UHsAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, Strength, OldStrength);
}

void UHsAttributeSet::OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, Endurance, OldEndurance);
}

void UHsAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, Dexterity, OldDexterity);
}

void UHsAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, Intelligence, OldIntelligence);
}
