#include "BTS_PlayerLocationseen.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTS_PlayerLocationseen::UBTS_PlayerLocationseen()
{
	//BT에 노출되는 노드 이름
	NodeName = "Update Player Location if Seen";
}

void UBTS_PlayerLocationseen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
	{
		return;
	}

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn) == true)//시야에 들어옴
	{
		//BT에 바인딩한 블랙보드 키에 폰을 설정
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	}
	else
	{
		//해당 블랙보드 키를 지운다
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
