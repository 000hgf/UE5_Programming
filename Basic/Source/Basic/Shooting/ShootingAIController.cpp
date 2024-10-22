#include "ShootingAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/MCharShooting.h"

void AShootingAIController::BeginPlay()
{
	Super::BeginPlay();
	
	if (EnemyBT != nullptr)
	{
		RunBehaviorTree(EnemyBT);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		SetFocus(PlayerPawn);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocationKey"),GetPawn()->GetActorLocation());
	}
}

void AShootingAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	//if (LineOfSightTo(PlayerPawn)==true)//시야에 들어옴
	//{
	//	SetFocus(PlayerPawn);
	//	MoveToActor(PlayerPawn,200); //2미터 반경 까지만 움직임
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	StopMovement();
	//}
}

bool AShootingAIController::IsDead() const
{
	AMCharShooting* ControlledCharacter = Cast<AMCharShooting>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}
	return true;
}
