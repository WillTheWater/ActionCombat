// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Character/SRS_MainCharacter.h"


ASRS_MainCharacter::ASRS_MainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASRS_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASRS_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

