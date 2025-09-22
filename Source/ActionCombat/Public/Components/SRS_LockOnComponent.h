// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRS_LockOnComponent.generated.h"


class UCharacterMovementComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class ACTIONCOMBAT_API USRS_LockOnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USRS_LockOnComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void ToggleLockOn(float TraceRadius = 800.f);

	bool IsLockOnActive() const { return bIsLockOnActive; }
	AActor* GetTargetActor() const { return TargetActor.Get(); }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ACharacter* OwnerCharacter;

	UPROPERTY()
	APlayerController* OwnerController;

	UPROPERTY()
	UCharacterMovementComponent* OwnerMovementComponent;

	bool bIsLockOnActive { false };

	TWeakObjectPtr<AActor> TargetActor;
};
