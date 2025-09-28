// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "HsDamageAbility.h"
#include "h_s/Actors/HsProjectile.h"
#include "ProjectileAbility.generated.h"

UCLASS()
class H_S_API UProjectileAbility : public UHsDamageAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SpawnProjectile(TSubclassOf<AHsProjectile> ProjectileClass) const;
};
