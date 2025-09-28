// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "ProjectileAbility.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "h_s/Actors/HsProjectile.h"

void UProjectileAbility::SpawnProjectile(const TSubclassOf<AHsProjectile> ProjectileClass) const
{
	AActor* AvatarActor = AbilityActorInfo->AvatarActor.Get();
	if (!AvatarActor) return;

	const FVector AvatarPosition = AvatarActor->GetActorLocation();
	const FRotator AvatarRotation = AvatarActor->GetActorRotation();

	const FTransform SpawnTransform(AvatarRotation, AvatarPosition);

	const auto Projectile = GetWorld()->SpawnActorDeferred<AHsProjectile>(
		ProjectileClass,
		SpawnTransform,
		AvatarActor,
		Cast<APawn>(AvatarActor),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
	);

	if (Projectile)
	{
		/*const UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(AvatarActor);

		FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
		EffectContextHandle.SetAbility(this);
		EffectContextHandle.AddSourceObject(Projectile);
		TArray<TWeakObjectPtr<AActor>> Actors;
		Actors.Add(Projectile);
		EffectContextHandle.AddActors(Actors);
		const FHitResult HitResult;
		EffectContextHandle.AddHitResult(HitResult);*/
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}