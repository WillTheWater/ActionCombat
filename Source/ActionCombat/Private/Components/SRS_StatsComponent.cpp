// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_StatsComponent.h"

#include "Kismet/KismetMathLibrary.h"


USRS_StatsComponent::USRS_StatsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}

void USRS_StatsComponent::ReduceHealth(float Damage)
{
	if (Stats[EStats::Health] <= 0) { return; }
	Stats[EStats::Health] -= Damage;
	Stats[EStats::Health] = UKismetMathLibrary::FClamp(Stats[EStats::Health], 0.0f, Stats[EStats::MaxHealth]);
}

void USRS_StatsComponent::BeginPlay()
{
	Super::BeginPlay();
	
}
