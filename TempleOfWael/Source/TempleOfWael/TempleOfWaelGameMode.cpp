// Copyright Epic Games, Inc. All Rights Reserved.

#include "TempleOfWaelGameMode.h"
#include "TempleOfWaelHUD.h"
#include "TempleOfWaelCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATempleOfWaelGameMode::ATempleOfWaelGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATempleOfWaelHUD::StaticClass();
}
