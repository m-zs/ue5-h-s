// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "PlayerCharacter.h"
#include "CharacterClassInfo.h"
#include "h_s/HSGameModeBase.h"
#include "h_s/Core/HsPlayerState.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"
#include "h_s/GASP/Attributes/HsAttributeSet.h"
#include "h_s/Lib/AbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Server
void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	SetupCharacter();
}

// Client
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

	if (!HasAuthority())
		return;
	UE_LOG(LogTemp, Log, TEXT("SetupCharacter"));
	const AHSGameModeBase* GameMode = Cast<AHSGameModeBase>(UGameplayStatics::GetGameMode(this));
	UAbilitySystemLibrary::InitializeDefaultAttributes(1, AbilitySystemComponent, GameMode->CharacterClassInfoData->CharacterClassInfo[CharacterClass]);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetCurrentHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
		OnHealthChanged.Broadcast(Data.NewValue);
	});
}
