// Fill out your copyright notice in the Description page of Project Settings.


#include "ChasePlayer.h"
#include "MeleeAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "blackboard_keys.h"

UChasePlayer::UChasePlayer(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	AMeleeAIController* const cont = Cast<AMeleeAIController>(owner_comp.GetAIOwner());
	FVector const player_location = cont->get_blackboard()->GetValueAsVector(bb_keys::target_location);

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, player_location);
=======
	if (Isdead == false)
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, player_location);

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
