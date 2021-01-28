// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERP_API UPool : public UActorComponent
{
	GENERATED_BODY()

	
	TArray<AActor*> Pila;

public:	

	// Sets default values for this component's properties
	UPool();

	AActor* Estrai(); // togli un elemento dalla pool 
	void Inserisci(AActor* DaInserire); // inserisci un elemento nella pool
	void Aggiungi(AActor* DaInserire); // aggiungi un elemento alla pool 

};
