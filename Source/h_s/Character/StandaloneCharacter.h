// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#pragma once

#include "CoreMinimal.h"
#include "AsCharacter.h"
#include "StandaloneCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, const FVector&, HitImpulse);

UCLASS()
class H_S_API AStandaloneCharacter : public AAsCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStandaloneCharacter();

	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;

	virtual void Die(const FVector& HitImpulse) override;

	virtual UHsAbilitySystemComponent* GetAbilitySystemComponent() const override {	return AbilitySystemComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupCharacter() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
