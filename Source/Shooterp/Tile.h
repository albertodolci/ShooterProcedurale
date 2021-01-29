// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class SHOOTERP_API ATile : public AActor
{
	GENERATED_BODY()
	
	class UPool* pool = nullptr;


public:	
	// Sets default values for this actor's properties
	ATile();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintImplementableEvent,Category = "Attach")
	FTransform GetAttachedArrow();
	
	UFUNCTION(BlueprintCallable,Category = "Procedurale")
	void InserisciAttori
	(TSubclassOf<AActor> DaCreare, int32 Minimo, int32 Massimo, float raggio, float ScalaMin, float ScalaMax);

	void InsAttore(TSubclassOf<AActor>& DaCreare, const FVector& SpawnPoint, float scala);

	UFUNCTION(BlueprintCallable, Category = "Procedurale")
		void InserisciNemici
		(TSubclassOf<APawn> DaCreare, int32 Minimo, int32 Massimo, float raggio);

	void InsNemico(TSubclassOf<APawn>& DaCreare, const FVector& SpawnPoint);

	//static int32 score;

	bool CastSphere(FVector luogo, float raggio);

	bool TrovaSpazioVuoto(FVector& Spawn, float Raggio);

	virtual void Tick(float DeltaTime) override;

	void SetPool(UPool* nwep);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PosizionaNavMesh();
	
	AActor* NMesh;

};
