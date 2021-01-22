// Fill out your copyright notice in the Description page of Project Settings.


#include "grass.h"

void Ugrass::CreaErba()
{
	for (int i = 0; i < CountSpawn; i++)
	{
		FVector Locazione = FMath::RandPointInBox(EstensioneSpawn);
		AddInstance(FTransform(Locazione));
	}

}

void Ugrass::BeginPlay()
{
	Super::BeginPlay();
	CreaErba();
}
