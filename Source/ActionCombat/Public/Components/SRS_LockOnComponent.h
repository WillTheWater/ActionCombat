// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRS_LockOnComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnLockOnTarget, USRS_LockOnComponent, OnLockOnTarget, AActor*, TargetActor);

class UCharacterMovementComponent;
class USpringArmComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable, PrioritizeCategories="Action Combat")
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

	UPROPERTY(BlueprintAssignable, Category = "Action Combat")
	FOnLockOnTarget OnLockOnTarget;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ACharacter* OwnerCharacter;

	UPROPERTY()
	APlayerController* OwnerController;

	UPROPERTY()
	UCharacterMovementComponent* OwnerMovementComponent;

	UPROPERTY()
	USpringArmComponent* OwnerSpringArm;

	bool bIsLockOnActive { false };

	TWeakObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	float MaxLockOnDistance { 1200.f };

	void BreakLockOn();
};
