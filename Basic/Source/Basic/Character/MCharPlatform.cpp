#include "MCharPlatform.h"
#include "../MGameInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlatformPlayerController.h"

AMCharPlatform::AMCharPlatform()
{
}

void AMCharPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult res;
	GetCharacterMovement()->K2_MoveUpdatedComponent(FVector(1.0, 1.0, 0.0), GetActorRotation(), res);
	GetCharacterMovement()->K2_MoveUpdatedComponent(FVector(-1.0, -1.0, 0.0), GetActorRotation(), res);
}

void AMCharPlatform::BeginPlay()
{
	Super::BeginPlay();

	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		DelegateHandle = MGI->MD_GameEnd.AddUObject(this, &ThisClass::SetGameEvent);
	}
}

void AMCharPlatform::SetGameEvent(int32 Type)
{
	if (APlatFormPlayerController* PlatformPlayerController = Cast<APlatFormPlayerController>(GetController()))
	{
		PlatformPlayerController->GameHasEnded(nullptr, Type ? true : false);
	}
}
