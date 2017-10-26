// Copyright (c) 2017 Martins Fridenbergs

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollRouteComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Patrol Points
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrollRouteComponent = ControlledPawn->FindComponentByClass<UPatrollRouteComponent>();

	if (!ensure(PatrollRouteComponent)) { return EBTNodeResult::Failed; }
	
	auto PatrollPoints = PatrollRouteComponent->GetPatrollPoints();
	if (PatrollPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s missing PatrollPoints!"), *ControlledPawn->GetName());
		return EBTNodeResult::Failed;
	}


	//Set Next Waypoint
	auto BlackbordComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackbordComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackbordComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrollPoints[Index]);

	//Cycle the Index
	auto NextIndex = (Index + 1) % PatrollPoints.Num();
	BlackbordComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}

