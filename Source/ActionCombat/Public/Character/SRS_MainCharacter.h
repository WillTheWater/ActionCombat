// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/SRS_FighterInterface.h"
#include "Interfaces/SRS_PlayerInterface.h"
#include "SRS_MainCharacter.generated.h"

class USRS_PlayerActionsComponent;
class USRS_BlockComponent;
class USRS_TraceComponent;
class USRS_LockOnComponent;
class USRS_CombatComponent;
class USRS_StatsComponent;
class USRS_PlayerAnimInstance;

UCLASS(PrioritizeCategories="Action Combat")
class ACTIONCOMBAT_API ASRS_MainCharacter : public ACharacter, public ISRS_PlayerInterface, public ISRS_FighterInterface
{
	GENERATED_BODY()

public:
	ASRS_MainCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float GetDamage() override;
	virtual bool HasEnoughStamina(float StaminaCost) override;

	USRS_StatsComponent* GetStatsComponent() const { return StatsComponent; }
	USRS_CombatComponent* GetCombatComponent() const { return CombatComponent; }
	USRS_LockOnComponent* GetLockOnComponent() const { return LockOnComponent; }
	USRS_TraceComponent* GetTraceComponent() const { return TraceComponent; }
	USRS_BlockComponent* GetBlockComponent() const { return BlockComponent; }
	USRS_PlayerActionsComponent* GetPlayerActionsComponent() const { return PlayerActionsComponent; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BLueprintReadOnly, Category = "Action Combat")
	USRS_PlayerAnimInstance* PlayerAnimInstance;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_StatsComponent* StatsComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_CombatComponent* CombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_LockOnComponent* LockOnComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_TraceComponent* TraceComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_BlockComponent* BlockComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Action Combat", meta = (AllowPrivateAccess = "true"))
	USRS_PlayerActionsComponent* PlayerActionsComponent;
};
