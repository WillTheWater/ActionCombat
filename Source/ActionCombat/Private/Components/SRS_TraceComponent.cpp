// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_TraceComponent.h"


USRS_TraceComponent::USRS_TraceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USRS_TraceComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerSkeletalMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
	
}


void USRS_TraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector StartLocation = OwnerSkeletalMesh->GetSocketLocation(TraceSocketStart);
	FVector EndLocation = OwnerSkeletalMesh->GetSocketLocation(TraceSocketEnd);
	FQuat Rotation = OwnerSkeletalMesh->GetSocketQuaternion(TraceSocketRotation);
}

