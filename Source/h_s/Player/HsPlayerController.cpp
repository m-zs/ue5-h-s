// All rights reserved. No permission is granted to use, copy, modify, or distribute this software for any purpose without explicit written permission from the author.

#include "HsPlayerController.h"
#include "h_s/Core/HsPlayerState.h"

void AHsPlayerController::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IsLocalController())
	{
		if (AHsPlayerState* PS = GetPlayerState<AHsPlayerState>(); PS && GetPawn())
		{
			const FRotator CurrentRotation =  GetPawn()->GetActorRotation();
			PS->UpdateReplicatedRotation(CurrentRotation);
		}
	}
}
