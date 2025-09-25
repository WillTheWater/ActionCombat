// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Animation/SRS_ToggleAttackTrace.h"

#include "Components/SRS_TraceComponent.h"

void USRS_ToggleAttackTrace::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                         float TotalDuration)
{
	USRS_TraceComponent* TraceComponent = MeshComp->GetOwner()->FindComponentByClass<USRS_TraceComponent>();
	if (!TraceComponent) { return; }

	TraceComponent->SetIsAttacking(true);
}

void USRS_ToggleAttackTrace::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	USRS_TraceComponent* TraceComponent = MeshComp->GetOwner()->FindComponentByClass<USRS_TraceComponent>();
	if (!TraceComponent) { return; }

	TraceComponent->SetIsAttacking(false);
}
