// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsPlayerState.h"
#include "AbilitySystemComponent.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"
#include "h_s/GASP/Attributes/HsAttributeSet.h"
#include "Net/UnrealNetwork.h"

AHsPlayerState::AHsPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHsAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHsAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100);
}

void AHsPlayerState::UpdateReplicatedRotation(const FRotator& NewRotation)
{
	if (HasAuthority())
	{
		ReplicatedRotation = NewRotation;
	}
	else
	{
		ServerUpdateRotation(NewRotation);
	}
}

void AHsPlayerState::ServerUpdateRotation_Implementation(const FRotator& NewRotation)
{
	ReplicatedRotation = NewRotation;
}

void AHsPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHsPlayerState, ReplicatedRotation);
}