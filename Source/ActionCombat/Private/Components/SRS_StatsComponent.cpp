// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_StatsComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


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

void USRS_StatsComponent::ReduceStamina(float StaminaCost)
{
	if (Stats[EStats::Stamina] <= 0) { return; }
	Stats[EStats::Stamina] -= StaminaCost;
	Stats[EStats::Stamina] = UKismetMathLibrary::FClamp(Stats[EStats::Stamina], 0.0f, Stats[EStats::MaxStamina]);
	bCanRegenStamina = false;

	FLatentActionInfo FunctionInfo
	{
		0,
		100,
		TEXT("EnableStaminaRegen"),
		this
	};
	UKismetSystemLibrary::RetriggerableDelay
	(
		GetWorld(),
		StaminaRegenDelay,
		FunctionInfo
	);
}

void USRS_StatsComponent::RegenStamina()
{
	if (!bCanRegenStamina) { return; }
	Stats[EStats::Stamina] = UKismetMathLibrary::FInterpTo_Constant
	(
		Stats[EStats::Stamina],
		Stats[EStats::MaxStamina],
		GetWorld()->DeltaTimeSeconds,
		StaminaRegenRate
	);
}

void USRS_StatsComponent::EnableStaminaRegen()
{
	bCanRegenStamina = true;
}
