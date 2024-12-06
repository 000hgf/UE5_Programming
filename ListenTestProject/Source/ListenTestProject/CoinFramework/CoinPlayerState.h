#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CoinPlayerState.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ACoinPlayerState : public APlayerState
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Score")
	int32 Pickups;

public:
	void AddPickup() { Pickups++; }
	int32 GetScore() { return Pickups; }
};
