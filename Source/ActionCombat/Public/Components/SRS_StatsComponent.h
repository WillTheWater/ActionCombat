// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnumTypes/SRS_Stats.h"
#include "SRS_StatsComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class ACTIONCOMBAT_API USRS_StatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USRS_StatsComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat")
	TMap<TEnumAsByte<EStats>, float> Stats;

	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void ReduceHealth(float Damage);
	
	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void ReduceStamina(float StaminaCost);
	
	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void RegenStamina();

	UFUNCTION()
	void EnableStaminaRegen();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	float StaminaRegenRate { 10.f };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	bool bCanRegenStamina { true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	float StaminaRegenDelay { 2.f };
};
