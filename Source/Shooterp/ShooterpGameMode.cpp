// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterpGameMode.h"
#include "ShooterpHUD.h"
#include "ShooterpCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Tile.h"
#include "EngineUtils.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "Pool.h"

AShooterpGameMode::AShooterpGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
    //static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Personaggi/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShooterpHUD::StaticClass();
    pool = CreateDefaultSubobject<UPool>(TEXT("pool"));
	

}

void AShooterpGameMode::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	RiempiLibreria();

	for (int i = 0; i < 4; i++)
	{
		CreaTile();
	}

}

void AShooterpGameMode::AggiungiALibreria(ANavMeshBoundsVolume* DaAggiungere)
{
	UE_LOG(LogTemp, Warning, TEXT("Found Actor %s"), *DaAggiungere->GetName());
	pool->Aggiungi(DaAggiungere);
}

void AShooterpGameMode::RiempiLibreria()
{
	auto NavMeshIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());

	while (NavMeshIterator)
	{

		AggiungiALibreria(*NavMeshIterator);
		++NavMeshIterator;
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
		new_tile->SetPool(pool);
	}

}
