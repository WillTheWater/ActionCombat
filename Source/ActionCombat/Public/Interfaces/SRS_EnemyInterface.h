// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SRS_EnemyInterface.generated.h"

UINTERFACE()
class USRS_EnemyInterface : public UInterface
{
	GENERATED_BODY()
};

class ACTIONCOMBAT_API ISRS_EnemyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ToggleLockOn(bool bIsLockedOn);
};
