// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SRS_MainCharacter.generated.h"

UCLASS(PrioritizeCategories="Action Combat")
class ACTIONCOMBAT_API ASRS_MainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASRS_MainCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
};
