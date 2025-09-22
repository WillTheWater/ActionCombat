// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_LockOnComponent.h"


USRS_LockOnComponent::USRS_LockOnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USRS_LockOnComponent::ToggleLockOn()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Lock On Toggled"));
}

void USRS_LockOnComponent::BeginPlay()
{
	Super::BeginPlay();
}
