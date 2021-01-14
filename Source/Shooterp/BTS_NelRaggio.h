// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_NelRaggio.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERP_API UBTS_NelRaggio : public UBTService
{
	GENERATED_BODY()

public:

		UPROPERTY(EditAnyWhere, Category = "Raggio")
		float Raggio = 500;
	    UPROPERTY(EditAnyWhere, Category = "Raggio")
	    struct FBlackboardKeySelector Nemico;
	    UPROPERTY(EditAnyWhere, Category = "Raggio")
		struct FBlackboardKeySelector bRaggio;

		virtual void TickNode( UBehaviorTreeComponent& OwnerComponent, uint8* NodeMedory,float DeltaSecond );



};
