// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "StandaloneCharacter.h"
#include "CharacterClassInfo.h"
#include "h_s/HSGameModeBase.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"
#include "h_s/GASP/Attributes/HsAttributeSet.h"
#include "h_s/Lib/AbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStandaloneCharacter::AStandaloneCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UHsAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

// Called when the game starts or when spawned
void AStandaloneCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetupCharacter();
}

void AStandaloneCharacter::SetupCharacter()
{
	Super::SetupCharacter();
	check(AbilitySystemComponent);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	if (!HasAuthority()) return;
	const AHSGameModeBase* GameMode = Cast<AHSGameModeBase>(UGameplayStatics::GetGameMode(this));
	UAbilitySystemLibrary::InitializeDefaultAttributes(1, AbilitySystemComponent, GameMode->CharacterClassInfoData->CharacterClassInfo[CharacterClass]);
}

// Called every frame
void AStandaloneCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AStandaloneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
