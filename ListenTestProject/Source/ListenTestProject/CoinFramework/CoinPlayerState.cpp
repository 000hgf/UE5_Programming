#include "CoinPlayerState.h"
#include "Net/UnrealNetwork.h"

void ACoinPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACoinPlayerState, Pickups);

}


