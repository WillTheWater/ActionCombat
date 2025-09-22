// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_LockOnComponent.h"


USRS_LockOnComponent::USRS_LockOnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USRS_LockOnComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USRS_LockOnComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

