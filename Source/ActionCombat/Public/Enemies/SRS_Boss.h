// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/SRS_EnemyInterface.h"
#include "SRS_Boss.generated.h"

class USRS_StatsComponent;

UCLASS()
class ACTIONCOMBAT_API ASRS_Boss : public ACharacter, public ISRS_EnemyInterface
{
	GENERATED_BODY()

public:
	ASRS_Boss();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_StatsComponent* StatsComponent;
};
