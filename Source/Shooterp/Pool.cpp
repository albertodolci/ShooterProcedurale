// Fill out your copyright notice in the Description page of Project Settings.


#include "Pool.h"

// Sets default values for this component's properties
UPool::UPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;



	// ...
}

AActor* UPool::Estrai()
{
	if (Pila.Num() > 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Estrai trovato"));

		return Pila.Pop();

	} else return nullptr;
}

void UPool::Inserisci(AActor* DaInserire)
{
	UE_LOG(LogTemp, Error , TEXT("oggetto inserito %s"), *DaInserire->GetName());
	Pila.Add(DaInserire);
}

void UPool::Aggiungi(AActor* DaInserire)
{

	UE_LOG(LogTemp, Error, TEXT("oggetto inserito %s"), *DaInserire->GetName());
	Pila.Add(DaInserire);
}
