#include "ShootingGameModeBase.h"
#include "EngineUtils.h"
#include "DebugMacros.h"
#include "ShootingAIController.h"

//게임 종료 처리 함수(bIsPlayerWin:true => 플레이어 승리)
void AShootingGameModeBase::EndGame(bool bIsPlayerWin)
{
	//레벨상의 모든 컨트롤러를 순회(월드에서 뭔가를 이터레이션에서 가져오는건 되도록 지양)
	//개별 pool을 만들어서 관리 + 컨테이너에서 가져오는게 정석
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		//if (bIsPlayerWin == true && Controller->IsPlayerController()==true)
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWin;
		{
			//플레이어 승리
			Controller->GameHasEnded(Controller->GetPawn(),bIsWinner);
		}
	}

	}

//나 또는 AI가 죽었을때
void AShootingGameModeBase::PawnKilled(APawn* PawnKilled)
{
	HLOG(Warning, TEXT("PawnKilled"));

	//죽은것이 플레이어
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}

	//AI들이 남아있으면 return
	for (AShootingAIController* Controller : TActorRange<AShootingAIController>(GetWorld()))
	{
		if(!Controller->IsDead())
		{
			//아직 살아있는 개체가 있다.
			return;
		}
	}
	EndGame(true);
}
