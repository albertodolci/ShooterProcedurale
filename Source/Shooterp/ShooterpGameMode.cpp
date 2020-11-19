// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterpGameMode.h"
#include "ShooterpHUD.h"
#include "ShooterpCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShooterpGameMode::AShooterpGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Personaggi/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShooterpHUD::StaticClass();
}
