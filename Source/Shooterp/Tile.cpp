// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "DrawDebugHelpers.h"
#include "Shooterp.h"
#include "Pool.h"
#include "ShooterpGameMode.h"
#include "NavigationSystem/Public/NavigationSystem.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATile::InserisciAttori(TSubclassOf<AActor> DaCreare, int32 Minimo, int32 Massimo,float raggio,float ScalaMin, float ScalaMax)
{
	// trovare il punto di spawn
	
	//
	int NumeroOggetti = FMath::RandRange(Minimo, Massimo);

	for (int i = 0; i < NumeroOggetti; i++)
	{
		FVector SpawnPoint;

		float scala = FMath::FRandRange(ScalaMin, ScalaMax);

		if ( TrovaSpazioVuoto(SpawnPoint, raggio*scala) )
		{
			InsAttore(DaCreare, SpawnPoint, scala);
	    }
	}


	
}

void ATile::InsAttore(TSubclassOf<AActor>& DaCreare, const FVector& SpawnPoint,float scala)
{
	AActor* Elemento = GetWorld()->SpawnActor<AActor>(DaCreare);
	Elemento->SetActorRelativeLocation(SpawnPoint);

	FRotator NewRot(0, FMath::RandRange(-180, 180), 0);
	Elemento->SetActorRelativeRotation(NewRot);

	Elemento->SetActorScale3D(FVector(scala, scala, scala));

	Elemento->AttachToActor
	(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

bool ATile::CastSphere(FVector luogo, float raggio)
{
	FHitResult risultato;

	FVector LuogoGlobale = ActorToWorld().TransformPosition(luogo);


	bool Colpito = GetWorld()->SweepSingleByChannel(
		risultato,
		LuogoGlobale,
		LuogoGlobale + FVector(0, 0.1, 0),
		FQuat::Identity,
		ECC_SPAWN,
		FCollisionShape::MakeSphere(raggio)
	    );

	//FColor Colore = Colpito ? FColor::Red : FColor::Green;
	//DrawDebugSphere(GetWorld(), LuogoGlobale, raggio, 10, Colore, true, 100);


	return Colpito;
}

bool ATile::TrovaSpazioVuoto(FVector& Spawn, float Raggio)
{

	FVector Min = FVector(0, -1650, 0);
	FVector Max = FVector(7050, 1650, 0);

	FBox Spazio(Min, Max);

	int MAX = 25;

	for (int i = 0; i < MAX; i++)
	{
		Spawn = FMath::RandPointInBox(Spazio);
		bool exit = CastSphere(Spawn, Raggio);
		if (!exit) return true;
	}

	return false;
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	TActorIterator<AActor> ActorIt = TActorIterator<AActor>(GetWorld());

	while (ActorIt)
	{
		AActor* FoundActor = *ActorIt;
		UE_LOG(LogTemp, Warning, TEXT("Found Actor %s"), *FoundActor->GetName());
		++ActorIt;
	}*/

}

void ATile::PosizionaNavMesh()
{
	NMesh = pool->Estrai();

	if (NMesh)
	{ // posiziona nav mesh
		FVector NewPos = GetActorLocation();
		NewPos.X += 3525;
    	NMesh->SetActorLocation(NewPos);
		FNavigationSystem::Build(*GetWorld());

		UE_LOG( LogTemp, Error, TEXT("Nav Mesh %s Assegnata a Tile %s"),*NMesh->GetName(),*GetName() );

	}
	else UE_LOG(LogTemp, Error, TEXT("No NavMesh Disponibili"));

}



void ATile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	TArray<AActor*> DaRipulire;
	GetAttachedActors(DaRipulire);

	for (int i = 0; i < DaRipulire.Num(); i++)
	{
		AShooterpGameMode::VDestroy(DaRipulire[i]);
	}

	pool->Inserisci(NMesh);
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::SetPool(UPool* nwep)
{
	pool = nwep;

	PosizionaNavMesh();
}

