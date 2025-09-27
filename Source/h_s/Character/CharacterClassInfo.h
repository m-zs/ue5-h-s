// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

class UGameplayAbility;
class UGameplayEffect;

UENUM(BlueprintType, Blueprintable)
enum class ECharacterClass : uint8
{
	Warrior
};

USTRUCT(Blueprintable)
struct FCharacterClassInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};

UCLASS()
class H_S_API UCharacterClassInfoData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TMap<ECharacterClass, FCharacterClassInfo> CharacterClassInfo;
};
