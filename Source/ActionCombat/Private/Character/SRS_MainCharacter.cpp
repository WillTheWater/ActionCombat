// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Character/SRS_MainCharacter.h"

#include "Animation/SRS_PlayerAnimInstance.h"


ASRS_MainCharacter::ASRS_MainCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASRS_MainCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerAnimInstance = Cast<USRS_PlayerAnimInstance>(GetMesh()->GetAnimInstance());
}

void ASRS_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

