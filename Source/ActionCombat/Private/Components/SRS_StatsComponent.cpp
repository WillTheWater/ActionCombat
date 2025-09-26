// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_StatsComponent.h"


USRS_StatsComponent::USRS_StatsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}

void USRS_StatsComponent::BeginPlay()
{
	Super::BeginPlay();
	
}