// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AsCharacter.generated.h"

enum class ECharacterClass : uint8;
class UGameplayEffect;
class UHsAbilitySystemComponent;
class UHsAttributeSet;

UCLASS()
class H_S_API AAsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAsCharacter();

	UFUNCTION(BlueprintCallable, Category = "Character")
	UHsAttributeSet* GetAttributeSet() const { return AttributeSet; }

	UFUNCTION(BlueprintCallable, Category = "Character")
	UHsAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	TArray<UGameplayEffect*> GameplayEffects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	ECharacterClass CharacterClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	int TeamID = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHsAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHsAbilitySystemComponent> AbilitySystemComponent;

	virtual void SetupCharacter();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
