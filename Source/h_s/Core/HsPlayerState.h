// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HsPlayerState.generated.h"

class UHsAbilitySystemComponent;
class UAbilitySystemComponent;
class UHsAttributeSet;

UCLASS()
class H_S_API AHsPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AHsPlayerState();

	UHsAttributeSet* GetAttributeSet() const { return AttributeSet; }

	UHsAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHsAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHsAbilitySystemComponent> AbilitySystemComponent;
};
