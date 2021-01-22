// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "grass.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTERP_API Ugrass : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FBox EstensioneSpawn;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	int CountSpawn;

	void CreaErba();

	virtual void BeginPlay() override;

};
