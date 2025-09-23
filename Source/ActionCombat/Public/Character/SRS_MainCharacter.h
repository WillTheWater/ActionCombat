// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/SRS_PlayerInterface.h"
#include "SRS_MainCharacter.generated.h"

class USRS_PlayerAnimInstance;

UCLASS(PrioritizeCategories="Action Combat")
class ACTIONCOMBAT_API ASRS_MainCharacter : public ACharacter, public ISRS_PlayerInterface
{
	GENERATED_BODY()

public:
	ASRS_MainCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BLueprintReadOnly, Category = "Action Combat")
	USRS_PlayerAnimInstance* PlayerAnimInstance;

private:
};
