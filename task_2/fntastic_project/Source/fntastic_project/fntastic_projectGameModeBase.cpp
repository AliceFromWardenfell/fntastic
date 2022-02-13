// Copyright Epic Games, Inc. All Rights Reserved.

#include "FP_Character.h"
#include "fntastic_projectGameModeBase.h"

Afntastic_projectGameModeBase::Afntastic_projectGameModeBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	DefaultPawnClass = ACharacter::StaticClass();
}
