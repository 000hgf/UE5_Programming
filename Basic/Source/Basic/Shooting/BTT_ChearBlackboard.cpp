#include "BTT_ClearBlackboard.h"
#include "Character/MCharShooting.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_ClearBlackboard::UBTT_ClearBlackboard()
{
	NodeName = TEXT("ClearBlackboard");
}

EBTNodeResult::Type UBTT_ClearBlackboard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}
