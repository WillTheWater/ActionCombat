// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_TraceComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


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
	
	float TraceDistance = FVector::Distance(StartLocation, EndLocation);
	FVector TraceBoxExtent = FVector(WeaponTraceLength, WeaponTraceLength, TraceDistance) / 2.0f;
	FCollisionShape TraceBox = FCollisionShape::MakeBox(TraceBoxExtent);
	FCollisionQueryParams TraceParams { FName("WeaponTrace"), false, GetOwner() };

	TArray<FHitResult> OutHits;
	bool bHasHitTarget = GetWorld()->SweepMultiByChannel
	(
		OutHits,
		StartLocation,
		EndLocation,
		Rotation,
		ECollisionChannel::ECC_GameTraceChannel1,
		TraceBox,
		TraceParams
	);

	if (bHasHitTarget)
	{
		// Do something with the hit results.
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hit!"));
	}
	if (bShouldDrawDebugShapes)
	{
		FVector Center = UKismetMathLibrary::VLerp(StartLocation, EndLocation, 0.5f);
		UKismetSystemLibrary::DrawDebugBox
		(
			GetWorld(),
			Center,
			TraceBox.GetExtent(),
			bHasHitTarget ? FColor::Red : FColor::Blue,
			Rotation.Rotator(),
			1.0f,
			1.50f
		);
	}
}

