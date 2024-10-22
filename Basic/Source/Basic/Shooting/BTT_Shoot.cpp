#include "BTT_Shoot.h"
#include "Character/MCharShooting.h"
#include "AIController.h"

UBTT_Shoot::UBTT_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AMCharShooting* MCharShooter = Cast<AMCharShooting>(OwnerComp.GetAIOwner()->GetPawn());
	if (MCharShooter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	MCharShooter->Shoot();

	return EBTNodeResult::Succeeded;
}
