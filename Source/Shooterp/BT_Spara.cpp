// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Spara.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "ContorolS.h"
#include "Guardia.h"

EBTNodeResult::Type UBT_Spara::ExecuteTask(UBehaviorTreeComponent& OwnerComp,uint8* NodeMemory)
{
	auto Controller = OwnerComp.GetAIOwner();
	auto Guardia =   Cast<AGuardia>(Controller->GetPawn());

	if (Guardia)
	{
		Guardia->OnFire();
		return  EBTNodeResult::Succeeded;
	}
	else return  EBTNodeResult::Failed;
}
