// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_LockOnComponent.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


USRS_LockOnComponent::USRS_LockOnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USRS_LockOnComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!bIsLockOnActive || !TargetActor.IsValid()) { return; }
	FVector OwnerLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation = TargetActor->GetActorLocation();
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(OwnerLocation, TargetLocation);
	OwnerController->SetControlRotation(TargetRotation);
}

void USRS_LockOnComponent::ToggleLockOn(float TraceRadius)
{
	bIsLockOnActive = !bIsLockOnActive;
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
	
	if (bIsLockOnActive && HasFoundTarget && Hit.GetActor())
	{
		TargetActor = Hit.GetActor();
		OwnerController->SetIgnoreLookInput(true);
		OwnerMovementComponent->bOrientRotationToMovement = false;
		OwnerMovementComponent->bUseControllerDesiredRotation = true;
	}
	else
	{
		TargetActor = nullptr;
		OwnerController->SetIgnoreLookInput(false);
		OwnerMovementComponent->bOrientRotationToMovement = true;
		OwnerMovementComponent->bUseControllerDesiredRotation = false;
	}
}

void USRS_LockOnComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	OwnerController = Cast<APlayerController>(OwnerCharacter->GetController());
	OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
}
