// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackMelee.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "MeleeAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "blackboard_keys.h"

UAttackMelee::UAttackMelee(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Melee Atack");
}

EBTNodeResult::Type UAttackMelee::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	auto const cont = Cast<AMeleeAIController>(owner_comp.GetAIOwner());
	auto const npc = cont->GetCharacter();
	UCharacterMovementComponent* mov = npc->GetCharacterMovement();
	mov->MaxWalkSpeed = 0;
	return EBTNodeResult::Succeeded;
}
