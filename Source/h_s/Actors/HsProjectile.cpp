// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "h_s/Character/AsCharacter.h"
#include "h_s/GASP/ASC/HsAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
AHsProjectile::AHsProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("UProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 550;
	ProjectileMovementComponent->MaxSpeed = 550;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void AHsProjectile::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(Lifespan);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AHsProjectile::OnSphereOverlap);
}

void AHsProjectile::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == GetOwner() || !HasAuthority())
	{
		return;
	}

	const AAsCharacter* Target= Cast<AAsCharacter>(OtherActor);
	const AAsCharacter* Initiator = Target;

	/*if (Initiator->TeamID == Target->TeamID)
	{
		return;
	}*/

	FGameplayEffectContextHandle EffectContextHandle = Initiator->GetAbilitySystemComponent()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(Initiator->GetAbilitySystemComponent()->GetAvatarActor());

	const FGameplayEffectSpecHandle SpecHandle = Initiator->GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, 1, EffectContextHandle);

	Target->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
}

// Called every frame
void AHsProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
