// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemLibrary.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UAbilitySystemComponent;
struct FCharacterClassInfo;

UCLASS()
class H_S_API UAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AbilitySystemLibrary|Character")
	static void InitializeDefaultAttributes(const float Level, UAbilitySystemComponent* Asc, const FCharacterClassInfo ClassInfo);

	UFUNCTION(BlueprintCallable, Category="AbilitySystemLibrary|Character")
	static void ApplyEffectContextHandleToTarget(AActor* Avatar, float Level, UAbilitySystemComponent* Asc, TSubclassOf<UGameplayEffect> Effect);
};
