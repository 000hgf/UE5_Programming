#include "CoinGameState.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerState.h"
#include "../ETC/Coinitem.h"
#include "Net/UnrealNetwork.h"

void ACoinGameState::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> CoinitemArr;
	UGameplayStatics::GetAllActorsOfClass(this, ACoinitem::StaticClass(), CoinitemArr);

	PickupsRemain = CoinitemArr.Num();
}

TArray<APlayerState*> ACoinGameState::GetPlayerStateOrderedByScore() const
{
	TArray<APlayerState*> PlayerStates(PlayerArray);
	PlayerStates.Sort([](const APlayerState& A, const APlayerState& B)
		{
			return A.GetScore() > B.GetScore();
		}
	);

	return PlayerStates;
}

void ACoinGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACoinGameState, PickupsRemain);
}