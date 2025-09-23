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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat")
	float Direction { 0.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat")
	bool bIsInCombat { false };

	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void UpdateVelocity();
};
