// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "h_s/Character/AsCharacter.h"
#include "HsDamageAbility.generated.h"

UCLASS()
class H_S_API UHsDamageAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
	TSubclassOf<UGameplayEffect> DamageEffect;

	UFUNCTION(BlueprintCallable, Category="Ability")
	void DoDamage(AAsCharacter* Initiator, AAsCharacter* Target) const;

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	const FGameplayAbilityActorInfo* AbilityActorInfo;
};
