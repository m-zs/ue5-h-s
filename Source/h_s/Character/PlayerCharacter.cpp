// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "PlayerCharacter.h"
#include "h_s/Core/HsPlayerState.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	SetupCharacter();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	SetupCharacter();
}

void APlayerCharacter::SetupCharacter()
{
	Super::SetupCharacter();
	AHsPlayerState* State = GetPlayerState<AHsPlayerState>();
	check(State);
	State->GetAbilitySystemComponent()->InitAbilityActorInfo(State, this);
	AbilitySystemComponent = State->GetAbilitySystemComponent();
	AttributeSet = State->GetAttributeSet();
}
