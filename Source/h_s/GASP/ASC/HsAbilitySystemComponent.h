// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "h_s/GASP/Attributes/HsAttributeSet.h"
#include "HsAbilitySystemComponent.generated.h"

UCLASS()
class H_S_API UHsAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	TObjectPtr<UHsAttributeSet>&& GetAttributeSet();
};
