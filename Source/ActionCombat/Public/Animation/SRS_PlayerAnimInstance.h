// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SRS_PlayerAnimInstance.generated.h"

UCLASS(PrioritizeCategories="Action Combat")
class ACTIONCOMBAT_API USRS_PlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat")
	float Velocity { 0.f };

	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void UpdateVelocity();
};
