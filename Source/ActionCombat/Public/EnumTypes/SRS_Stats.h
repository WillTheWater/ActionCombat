#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum EStats
{
	None UMETA(DisplayName = "None Selected"),
	Health UMETA(DisplayName = "Health"),
	MaxHealth UMETA(DisplayName = "Max Health"),
	Stamina UMETA(DisplayName = "Stamina"),
	MaxStamina UMETA(DisplayName = "Max Stamina"),
	Strength UMETA(DisplayName = "Strength"),
	MaxStrength UMETA(DisplayName = "Max Strength"),
	Mana UMETA(DisplayName = "Mana"),
	MaxMana UMETA(DisplayName = "Max Mana"),
	Experience UMETA(DisplayName = "Experience"),
	MaxExperience UMETA(DisplayName = "Max Experience"),
	Level UMETA(DisplayName = "Level"),
	MaxLevel UMETA(DisplayName = "Max Level")
};
