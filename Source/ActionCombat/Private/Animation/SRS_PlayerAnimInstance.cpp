// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Animation/SRS_PlayerAnimInstance.h"

#include "KismetAnimationLibrary.h"

void USRS_PlayerAnimInstance::UpdateTarget(AActor* Target)
{
	bIsInCombat = IsValid(Target);
}

void USRS_PlayerAnimInstance::UpdateVelocity()
{
	APawn* PlayerPawn = TryGetPawnOwner();
	if (PlayerPawn)
	{
		Velocity = PlayerPawn->GetVelocity().Length();
	}
}

void USRS_PlayerAnimInstance::UpdateDirection()
{
	APawn* PlayerPawn = TryGetPawnOwner();
	if (PlayerPawn && bIsInCombat)
	{
		Direction = UKismetAnimationLibrary::CalculateDirection(PlayerPawn->GetVelocity(), PlayerPawn->GetActorRotation());
	}
}
