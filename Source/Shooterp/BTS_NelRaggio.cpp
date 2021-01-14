// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_NelRaggio.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "ContorolS.h"

void UBTS_NelRaggio::TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMedory, float DeltaSecond)
{

	auto Controller = OwnerComponent.GetAIOwner();
	auto MyPawn = Controller->GetPawn();
    auto lavagna = OwnerComponent.GetBlackboardComponent();
	auto ENmPawn = Cast<APawn>(lavagna->GetValueAsObject(Nemico.SelectedKeyName));

	if (MyPawn && ENmPawn)
	{
		if ( (MyPawn->GetActorLocation() - ENmPawn->GetActorLocation() ).Size() > Raggio)
		{
			
			lavagna->SetValueAsBool(bRaggio.SelectedKeyName,false);
		}
		else
		{
			lavagna->SetValueAsBool(bRaggio.SelectedKeyName,true);

		}


	}

	//	int index = lavagna->GetValueAsInt(IndexKey.SelectedKeyName);


}
