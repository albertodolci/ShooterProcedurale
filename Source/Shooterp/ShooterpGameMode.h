// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterpGameMode.generated.h"

UCLASS(minimalapi)
class AShooterpGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	void AggiungiALibreria(class ANavMeshBoundsVolume* DaAggiungere);

	UFUNCTION(BluePrintCallable, Category = "Libreria")
		void RiempiLibreria();

public:


	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "pool")
		class UPool* pool = nullptr;


	UWorld* World = nullptr;

	FVector SpawnPoint = FVector(0, 0, 0);

	UPROPERTY(EditAnyWhere,Category = "Tiles")
	TSubclassOf<class ATile> MyTile;

	AShooterpGameMode();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Destroy")
	static void VDestroy(UObject* ToDestroy);


	UFUNCTION(BlueprintCallable,Category = "tiles")
	void CreaTile();

};



