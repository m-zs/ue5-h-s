// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

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

	//Sphere->OnComponentBeginOverlap.AddDynamic(this, &AHsProjectile::OnSphereOverlap);
}

// Called every frame
void AHsProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

