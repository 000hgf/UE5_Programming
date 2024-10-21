#include "ShootingAIController.h"
#include "Kismet/GameplayStatics.h"

void AShootingAIController::BeginPlay()
{
	Super::BeginPlay();

}

void AShootingAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if (LineOfSightTo(PlayerPawn)==true)//시야에 들어옴
	{
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn,200); //2미터 반경 까지만 움직임
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}
}
