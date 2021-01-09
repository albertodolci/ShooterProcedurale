// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterpGameMode.h"
#include "ShooterpHUD.h"
#include "ShooterpCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Tile.h"

AShooterpGameMode::AShooterpGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
    //static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Personaggi/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShooterpHUD::StaticClass();
}

void AShooterpGameMode::BeginPlay()
{
	World = GetWorld();

	for (int i = 0; i < 4; i++)
	{
		CreaTile();
	}

}

void AShooterpGameMode::VDestroy(UObject* ToDestroy)
{
	if (!ToDestroy) return;
	if (!ToDestroy->IsValidLowLevel()) return;

	auto IsActor = Cast<AActor>(ToDestroy);

	if (IsActor)
	{
		IsActor->K2_DestroyActor();
		ToDestroy = nullptr;
	}
	else
	{
    	ToDestroy->ConditionalBeginDestroy();
		ToDestroy = nullptr;
	}

	GEngine->ForceGarbageCollection(true);

}

void AShooterpGameMode::CreaTile()
{
	
	if (World)
	{
		auto new_tile = World->SpawnActor<ATile>(MyTile, SpawnPoint, FRotator(0, 0, 0));
		SpawnPoint = new_tile->GetAttachedArrow().GetTranslation();
	}

}
