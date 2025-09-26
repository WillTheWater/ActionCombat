// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Enemies/SRS_Boss.h"

#include "Components/SRS_StatsComponent.h"


ASRS_Boss::ASRS_Boss()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	StatsComponent = CreateDefaultSubobject<USRS_StatsComponent>(TEXT("Stats Component"));
}

void ASRS_Boss::BeginPlay()
{
	Super::BeginPlay();
}