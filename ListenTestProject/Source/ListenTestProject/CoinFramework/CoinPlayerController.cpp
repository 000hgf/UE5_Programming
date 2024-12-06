#include "CoinPlayerController.h"
#include "Blueprint/UserWidget.h"

void ACoinPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalController() && ScoreboardMenuClass!=nullptr)
	{
		ScoreboardMenu = CreateWidget<UUserWidget>(this, ScoreboardMenuClass);
		if (ScoreboardMenu)
		{
			ScoreboardMenu->AddToViewport(0);
		}
	}
}
