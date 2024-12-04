#include "NetworkBasicController.h"
#include "../ETC/HDebugMacros.h"


void ANetworkBasicController::BeginPlay()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::BeginPlay();
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));
}

void ANetworkBasicController::OnPossess(APawn* InPawn)
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::OnPossess(InPawn);
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));
}
