// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Enemies/SRS_Boss.h"


ASRS_Boss::ASRS_Boss()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASRS_Boss::BeginPlay()
{
	Super::BeginPlay();
}

void ASRS_Boss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

