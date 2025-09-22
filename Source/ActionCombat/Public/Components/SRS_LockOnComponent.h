// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRS_LockOnComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class ACTIONCOMBAT_API USRS_LockOnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USRS_LockOnComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
};
