// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "h_s/Character/CombatInterface.h"

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

	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, ElementalResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, Armour, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, ElementalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, PhysicalDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, AreaOfEffect, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, ActionSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHsAttributeSet, MaxElementalResistance, COND_None, REPNOTIFY_Always);
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

void UHsAttributeSet::OnRep_ElementalResistance(const FGameplayAttributeData& OldElementalResistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, ElementalResistance, OldElementalResistance);
}

void UHsAttributeSet::OnRep_Armour(const FGameplayAttributeData& OldArmour) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, Armour, OldArmour);
}

void UHsAttributeSet::OnRep_ElementalDamage(const FGameplayAttributeData& OldElementalDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, ElementalDamage, OldElementalDamage);
}

void UHsAttributeSet::OnRep_PhysicalDamage(const FGameplayAttributeData& OldPhysicalDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, PhysicalDamage, OldPhysicalDamage);
}

void UHsAttributeSet::OnRep_AreaOfEffect(const FGameplayAttributeData& OldAreaOfEffect) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, AreaOfEffect, OldAreaOfEffect);
}

void UHsAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UHsAttributeSet::OnRep_ActionSpeed(const FGameplayAttributeData& OldActionSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, ActionSpeed, OldActionSpeed);
}

void UHsAttributeSet::OnRep_MaxElementalResistance(const FGameplayAttributeData& OldMaxElementalResistance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHsAttributeSet, MaxElementalResistance, OldMaxElementalResistance);
}

void UHsAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetCurrentHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxHealth.GetCurrentValue());
	}

	if (Attribute == GetElementalResistanceAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxElementalResistance.GetCurrentValue());
	}
}

void UHsAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
}

void UHsAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		if (GetCurrentHealth() <= 0)
		{
			if (Data.Target.GetAvatarActor()->Implements<UCombatInterface>())
			{
				Cast<ICombatInterface>(Data.Target.GetAvatarActor())->Die(*new FVector());
			}
		}
		SetCurrentHealth(FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetElementalResistanceAttribute())
	{
		SetElementalResistance(FMath::Clamp(GetElementalResistance(), 0.f, MaxElementalResistance.GetCurrentValue()));
	}
}
