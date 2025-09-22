// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_LockOnComponent.h"


USRS_LockOnComponent::USRS_LockOnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USRS_LockOnComponent::ToggleLockOn(float TraceRadius)
{
	FHitResult Hit;
	FVector Start = GetOwner()->GetActorLocation();
	FCollisionShape Shape = FCollisionShape::MakeSphere(TraceRadius);
	FCollisionQueryParams Params { FName("LockOn"), false, GetOwner()};
	
	bool HasFoundTarget = GetWorld()->SweepSingleByChannel
	(
		Hit,
		Start,
		Start,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		Shape,
		Params
	);
	if (HasFoundTarget)
	{
		FString DebugMessage = FString::Printf(TEXT("Lock On Toggled: %s"), *Hit.GetActor()->GetName());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, DebugMessage);
	}
}

void USRS_LockOnComponent::BeginPlay()
{
	Super::BeginPlay();
}
