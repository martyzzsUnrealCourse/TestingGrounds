// Copyright (c) 2017 Martins Fridenbergs

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrollRouteComponent.generated.h"

class AActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrollRouteComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	TArray<AActor*> GetPatrollPoints();

private:
	// Sets default values for this component's properties
	UPatrollRouteComponent();

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrollPoints;
	
};
