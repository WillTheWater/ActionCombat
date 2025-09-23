// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/SRS_EnemyInterface.h"
#include "SRS_Boss.generated.h"

UCLASS()
class ACTIONCOMBAT_API ASRS_Boss : public ACharacter, public ISRS_EnemyInterface
{
	GENERATED_BODY()

public:
	ASRS_Boss();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
};
