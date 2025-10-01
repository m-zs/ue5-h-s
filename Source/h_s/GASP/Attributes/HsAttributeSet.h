// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HsAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)           \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)               \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)               \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UHsAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UHsAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	// Current Health
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, CurrentHealth)

	// Max Health
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, MaxHealth)

	// Base Stats
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, Strength)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Endurance)
	FGameplayAttributeData Endurance;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, Endurance)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Dexterity)
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, Dexterity)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, Intelligence)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElementalResistance)
	FGameplayAttributeData ElementalResistance;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, ElementalResistance)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxElementalResistance)
	FGameplayAttributeData MaxElementalResistance;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, MaxElementalResistance)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Armour)
	FGameplayAttributeData Armour;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, Armour)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ElementalDamage)
	FGameplayAttributeData ElementalDamage;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, ElementalDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PhysicalDamage)
	FGameplayAttributeData PhysicalDamage;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, PhysicalDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AreaOfEffect)
	FGameplayAttributeData AreaOfEffect;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, AreaOfEffect)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MovementSpeed)
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, MovementSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ActionSpeed)
	FGameplayAttributeData ActionSpeed;
	ATTRIBUTE_ACCESSORS(UHsAttributeSet, ActionSpeed)

protected:
	UFUNCTION()
	void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_ElementalResistance(const FGameplayAttributeData& OldElementalResistance) const;

	UFUNCTION()
	void OnRep_MaxElementalResistance(const FGameplayAttributeData& OldMaxElementalResistance) const;

	UFUNCTION()
	void OnRep_Armour(const FGameplayAttributeData& OldArmour) const;

	UFUNCTION()
	void OnRep_ElementalDamage(const FGameplayAttributeData& OldElementalDamage) const;

	UFUNCTION()
	void OnRep_PhysicalDamage(const FGameplayAttributeData& OldPhysicalDamage) const;

	UFUNCTION()
	void OnRep_AreaOfEffect(const FGameplayAttributeData& OldAreaOfEffect) const;

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const;

	UFUNCTION()
	void OnRep_ActionSpeed(const FGameplayAttributeData& OldActionSpeed) const;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
