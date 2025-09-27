// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "AbilitySystemLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "h_s/Character/CharacterClassInfo.h"

void UAbilitySystemLibrary::InitializeDefaultAttributes(const float Level, UAbilitySystemComponent* Asc, const FCharacterClassInfo ClassInfo)
{
	const auto Avatar = Asc->GetAvatarActor();
	ApplyEffectContextHandleToTarget(Avatar, Level, Asc, ClassInfo.PrimaryAttributes);
	ApplyEffectContextHandleToTarget(Avatar, Level, Asc, ClassInfo.SecondaryAttributes);
	ApplyEffectContextHandleToTarget(Avatar, Level, Asc, ClassInfo.VitalAttributes);
}

void UAbilitySystemLibrary::ApplyEffectContextHandleToTarget(AActor* Avatar, const float Level, UAbilitySystemComponent* Asc, TSubclassOf<UGameplayEffect> Effect)
{
	auto Handle = Asc->MakeEffectContext();
	Handle.AddSourceObject(Avatar);
	const FGameplayEffectSpecHandle Spec = Asc->MakeOutgoingSpec(Effect, Level, Handle);
	Asc->ApplyGameplayEffectSpecToSelf(*Spec.Data.Get());
}
