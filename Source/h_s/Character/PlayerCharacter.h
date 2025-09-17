// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "AsCharacter.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class H_S_API APlayerCharacter : public AAsCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void SetupCharacter() override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;
};
