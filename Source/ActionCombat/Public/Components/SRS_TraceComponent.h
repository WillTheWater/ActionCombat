// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRS_TraceComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable, PrioritizeCategories="Action Combat")
class ACTIONCOMBAT_API USRS_TraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USRS_TraceComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void HandleResetAttack();

	bool GetIsAttacking() const { return bIsAttacking; }
	void SetIsAttacking(bool bNewIsAttacking) { bIsAttacking = bNewIsAttacking; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	USkeletalMeshComponent* OwnerSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	FName TraceSocketStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	FName TraceSocketEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	FName TraceSocketRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	float WeaponTraceLength { 30.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	bool bShouldDrawDebugShapes { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	bool bIsAttacking { false };

	UPROPERTY()
	TArray<AActor*> TargetsToIgnore;
};
