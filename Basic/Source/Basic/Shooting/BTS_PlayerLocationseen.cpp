#include "BTS_PlayerLocationseen.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

UBTS_PlayerLocationseen::UBTS_PlayerLocationseen()
{
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
	}
	else
	{
		//지우고
	}
}
