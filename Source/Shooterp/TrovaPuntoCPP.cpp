// Fill out your copyright notice in the Description page of Project Settings.


#include "TrovaPuntoCPP.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "CompPatrolRoute.h"
#include "ContorolS.h"

EBTNodeResult::Type UTrovaPuntoCPP::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto Controller = OwnerComp.GetAIOwner();
	auto Route = Controller->GetPawn()->FindComponentByClass<UCompPatrolRoute>();

	if (Route)
	{		
		auto lavagna = OwnerComp.GetBlackboardComponent();
		int index = lavagna->GetValueAsInt(IndexKey.SelectedKeyName);

		lavagna->SetValueAsObject( TargetKey.SelectedKeyName, Route->PatrolPoints[index]);
		index = (index + 1) % Route->PatrolPoints.Num();
		lavagna->SetValueAsInt(IndexKey.SelectedKeyName, index);
		
		return EBTNodeResult::Succeeded;

	} else return EBTNodeResult::Failed;
}
