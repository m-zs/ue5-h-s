// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HsPlayerController.generated.h"

class UHsAbilitySystemComponent;

UCLASS()
class H_S_API AHsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
};
