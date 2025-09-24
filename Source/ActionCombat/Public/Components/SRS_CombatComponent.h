// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SRS_CombatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class ACTIONCOMBAT_API USRS_CombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USRS_CombatComponent();

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
};
