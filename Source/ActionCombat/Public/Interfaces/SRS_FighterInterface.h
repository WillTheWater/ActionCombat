// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SRS_FighterInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USRS_FighterInterface : public UInterface
{
	GENERATED_BODY()
};

class ACTIONCOMBAT_API ISRS_FighterInterface
{
	GENERATED_BODY()

public:
	virtual float GetDamage() { return 0.0f; }
};
