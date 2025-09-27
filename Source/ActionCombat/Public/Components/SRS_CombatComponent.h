// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRS_CombatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnAttack, USRS_CombatComponent, OnAttack, float, StaminaCost);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class ACTIONCOMBAT_API USRS_CombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USRS_CombatComponent();

	UPROPERTY(BlueprintAssignable, Category = "Action Combat")
	FOnAttack OnAttack;
	
	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void ComboAttack();

	UFUNCTION(BlueprintCallable, Category = "Action Combat")
	void ResetAttack();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> AttackMontages;

	UPROPERTY()
	ACharacter* OwnerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	int ComboCounter { 0 };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	bool bCanAttack { true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	float StaminaCost { 5.0f };
};
