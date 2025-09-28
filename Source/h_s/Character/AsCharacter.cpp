// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "AsCharacter.h"

#include "GameplayEffect.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"

// Sets default values
AAsCharacter::AAsCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

UHsAbilitySystemComponent* AAsCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAsCharacter::Die(const FVector& HitImpulse)
{
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetEnableGravity(true);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	GetMesh()->AddImpulse(HitImpulse, NAME_None, true);

	bDead = true;

	// Disable the Ability System Component and remove all effects
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->CancelAllAbilities();
		// Remove all active gameplay effects
		FGameplayEffectQuery Query;
		Query.OwningTagQuery = FGameplayTagQuery::MakeQuery_MatchAnyTags(FGameplayTagContainer());
		AbilitySystemComponent->RemoveActiveEffects(Query);
		AbilitySystemComponent->SetActive(false);
	}
}

// Called when the game starts or when spawned
void AAsCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAsCharacter::SetupCharacter()
{
}

// Called every frame
void AAsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
