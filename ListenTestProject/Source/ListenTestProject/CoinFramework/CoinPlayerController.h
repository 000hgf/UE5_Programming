#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CoinPlayerController.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ACoinPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf <class UUserWidget> ScoreboardMenuClass;
	
	UPROPERTY()
	class UUserWidget* ScoreboardMenu;

public:
	virtual void BeginPlay() override;
};
