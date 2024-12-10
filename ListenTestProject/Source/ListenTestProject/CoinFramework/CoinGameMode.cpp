#include "CoinGameMode.h"
#include "../ETC/HDebugMacros.h"
#include "CoinGameState.h"
#include "Kismet/GameplayStatics.h"
#include "../Character/CoinGameCharacter.h"

ACoinGameMode::ACoinGameMode()
{
	GConfig->GetInt(TEXT("Rule"), TEXT("PickupPoint"), PickupPoint, GGameIni);
	GConfig->GetInt(TEXT("Rule"), TEXT("FelloutPoint"), FelloutPoint, GGameIni);
}

void ACoinGameMode::BeginPlay()
{
	Super::BeginPlay();

	MyGameState = GetGameState<ACoinGameState>();
}

//게임이 시작되었을때
void ACoinGameMode::HandleMatchHasStarted()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::HandleMatchHasStarted();

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "TheGameHasStarted");
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));
}

//게임이 종료되었을때
void ACoinGameMode::HandleMatchHasEnded()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::HandleMatchHasEnded();

	TArray<AActor*> Characters;
	UGameplayStatics::GetAllActorsOfClass(this, ACoinGameCharacter::StaticClass(), Characters);
	for (AActor* Actor : Characters)
	{
		Actor->Destroy();
	}

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ACoinGameMode::RestartMap, 5.0f);

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "TheGameHasEnded");
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));
}

bool ACoinGameMode::ReadyToStartMatch_Implementation()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Game StartMatch"));
	return true;
}

bool ACoinGameMode::ReadyToEndMatch_Implementation()
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Game EndMatch"));
	return MyGameState!=nullptr && !MyGameState->HasPickups();
}

void ACoinGameMode::RestartMap() const
{
	GetWorld()->ServerTravel(GetWorld()->GetName());
}
