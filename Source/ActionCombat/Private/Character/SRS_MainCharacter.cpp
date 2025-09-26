// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Character/SRS_MainCharacter.h"

#include "Animation/SRS_PlayerAnimInstance.h"
#include "Components/SRS_BlockComponent.h"
#include "Components/SRS_CombatComponent.h"
#include "Components/SRS_LockOnComponent.h"
#include "Components/SRS_PlayerActionsComponent.h"
#include "Components/SRS_StatsComponent.h"
#include "Components/SRS_TraceComponent.h"


ASRS_MainCharacter::ASRS_MainCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	StatsComponent = CreateDefaultSubobject<USRS_StatsComponent>(TEXT("Stats Component"));
	CombatComponent = CreateDefaultSubobject<USRS_CombatComponent>(TEXT("Combat Component"));
	LockOnComponent = CreateDefaultSubobject<USRS_LockOnComponent>(TEXT("Lock On Component"));
	TraceComponent = CreateDefaultSubobject<USRS_TraceComponent>(TEXT("Trace Component"));
	BlockComponent = CreateDefaultSubobject<USRS_BlockComponent>(TEXT("Block Component"));
	PlayerActionsComponent = CreateDefaultSubobject<USRS_PlayerActionsComponent>(TEXT("Player Actions Component"));
}

void ASRS_MainCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerAnimInstance = Cast<USRS_PlayerAnimInstance>(GetMesh()->GetAnimInstance());
}

void ASRS_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float ASRS_MainCharacter::GetDamage()
{
	return StatsComponent->Stats[EStats::Strength];
}

