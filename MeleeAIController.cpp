// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Troll_Enemy.h"
AMeleeAIController::AMeleeAIController(FObjectInitializer const& object_initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/InfinityBladeAdversaries/Enemy/Enemy_Troll/Melee_BT.Melee_BT'"));
	if (obj.Succeeded())
	{
		btree = obj.Object;
	}
	behevior_tree_component = object_initializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComponent"));
	blackboard = object_initializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

}
void AMeleeAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(btree);
	behevior_tree_component->StartTree(*btree);
}

void AMeleeAIController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	if (blackboard)
	{
		blackboard->InitializeBlackboard(*btree->BlackboardAsset);
	}
}

UBlackboardComponent* AMeleeAIController::get_blackboard() const
{
	return blackboard;
}
