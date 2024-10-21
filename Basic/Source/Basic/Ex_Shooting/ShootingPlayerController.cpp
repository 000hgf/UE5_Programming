#include "ShootingPlayerController.h"
#include "Blueprint/UserWidget.h"

void AShootingPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}
