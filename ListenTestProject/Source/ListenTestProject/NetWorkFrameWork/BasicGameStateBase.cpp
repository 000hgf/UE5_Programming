#include "BasicGameStateBase.h"
#include "../ETC/HDebugMacros.h"

void ABasicGameStateBase::HandleBeginPlay()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::HandleBeginPlay();
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));
}

void ABasicGameStateBase::OnRep_ReplicatedHasBegunPlay()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::OnRep_ReplicatedHasBegunPlay();
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));
}
