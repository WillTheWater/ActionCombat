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
};
