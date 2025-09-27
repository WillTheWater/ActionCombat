// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_CombatComponent.h"

#include "GameFramework/Character.h"
#include "Interfaces/SRS_PlayerInterface.h"


USRS_CombatComponent::USRS_CombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void USRS_CombatComponent::ComboAttack()
{
	if (OwnerCharacter->Implements<USRS_PlayerInterface>())
	{
		ISRS_PlayerInterface* PlayerInterface = Cast<ISRS_PlayerInterface>(OwnerCharacter);
		if (!PlayerInterface || !PlayerInterface->HasEnoughStamina(StaminaCost)) { return;}
	}
	if (!bCanAttack) { return; }
	bCanAttack = false;
	OwnerCharacter->PlayAnimMontage(AttackMontages[ComboCounter]);
	ComboCounter++;
	if (ComboCounter >= AttackMontages.Num())
	{
		ComboCounter = 0;
	}
	OnAttack.Broadcast(StaminaCost);
}

void USRS_CombatComponent::ResetAttack()
{
	bCanAttack = true;
}

void USRS_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
}
