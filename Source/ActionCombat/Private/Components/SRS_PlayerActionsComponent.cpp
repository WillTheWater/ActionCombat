// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.


#include "Components/SRS_PlayerActionsComponent.h"


// Sets default values for this component's properties
USRS_PlayerActionsComponent::USRS_PlayerActionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USRS_PlayerActionsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USRS_PlayerActionsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

