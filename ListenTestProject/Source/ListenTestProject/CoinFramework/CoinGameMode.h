#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "CoinGameMode.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ACoinGameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	class ACoinGameState* MyGameState;

protected:
	virtual void BeginPlay();
	virtual void HandleMatchHasStarted() override;
	virtual void HandleMatchHasEnded() override;
	virtual bool ReadyToStartMatch_Implementation() override;
	virtual bool ReadyToEndMatch_Implementation() override;

	void RestartMap() const;
	
};
