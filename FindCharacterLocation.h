// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "FindCharacterLocation.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ROGUELIKEGAME_API UFindCharacterLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UFindCharacterLocation(FObjectInitializer const& object_initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AccessPrivateAccess = "true"))
		float search_radius = 3000.0f;
private:

};
