// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Animation/SRS_PlayerAnimInstance.h"

void USRS_PlayerAnimInstance::UpdateVelocity()
{
	APawn* PlayerPawn = TryGetPawnOwner();
	if (PlayerPawn)
	{
		Velocity = PlayerPawn->GetVelocity().Length();
	}
}
