// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HSGameModeBase.generated.h"

class UCharacterClassInfoData;
struct FCharacterClassInfo;

UCLASS()
class H_S_API AHSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GameModeBase")
	TObjectPtr<UCharacterClassInfoData> CharacterClassInfoData;
};
