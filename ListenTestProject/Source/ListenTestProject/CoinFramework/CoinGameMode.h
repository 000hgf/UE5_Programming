#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "CoinGameMode.generated.h"

UCLASS(config = CoinGameRule)
class LISTENTESTPROJECT_API ACoinGameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	class ACoinGameState* MyGameState;

public:
	UPROPERTY(Config)
	int32 PickupPoint;
	UPROPERTY(Config)
	int32 FelloutPoint;

protected:
	ACoinGameMode();
	virtual void BeginPlay();
	virtual void HandleMatchHasStarted() override;
	virtual void HandleMatchHasEnded() override;
	virtual bool ReadyToStartMatch_Implementation() override;
	virtual bool ReadyToEndMatch_Implementation() override;

	void RestartMap() const;
	
};
