#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "CoinGameState.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ACoinGameState : public AGameState
{
	GENERATED_BODY()
	
protected:
	//레벨에 남아있는 전체 코인수
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Pickup")
	int32 PickupsRemain;
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	TArray<APlayerState*> GetPlayerStateOrderedByScore() const;

public:
	void RemovePickup() { PickupsRemain--; }
	bool HasPickups() const { return PickupsRemain > 0; }
};
