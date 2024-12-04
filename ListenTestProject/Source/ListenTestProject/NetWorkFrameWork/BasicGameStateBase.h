#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BasicGameStateBase.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ABasicGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	virtual void HandleBeginPlay() override;
	virtual void OnRep_ReplicatedHasBegunPlay() override;
	
};
