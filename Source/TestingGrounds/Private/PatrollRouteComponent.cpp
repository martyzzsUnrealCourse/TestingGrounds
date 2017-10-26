// Copyright (c) 2017 Martins Fridenbergs

#include "PatrollRouteComponent.h"

#include "Runtime/Engine/Classes/GameFramework/Actor.h"


// Sets default values for this component's properties
UPatrollRouteComponent::UPatrollRouteComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<AActor*> UPatrollRouteComponent::GetPatrollPoints()
{
	return PatrollPoints;
}

