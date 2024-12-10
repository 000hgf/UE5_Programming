#include "Coinitem.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Sound/SoundBase.h"
#include "../Character/CoinGameCharacter.h"
#include "../CoinFramework/CoinGameState.h"
#include "../CoinFramework/CoinGameMode.h"
#include "../Component/itemBuffComponent.h"

ACoinitem::ACoinitem()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Mesh->SetCollisionProfileName("OverlapAll");

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovement");
	RotatingMovement->RotationRate = FRotator(0.0, 90.0f, 0.0);

	bReplicates = true;
}

void ACoinitem::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinitem::OnBeginOverlap);
}


void ACoinitem::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACoinGameCharacter* Character = Cast<ACoinGameCharacter>(OtherActor);

	if(!HasAuthority())
	{
		return;
	}

	ACoinGameState* GameState = Cast<ACoinGameState>(GetWorld()->GetGameState());
	if (GameState!=nullptr)
	{
		GameState->RemovePickup();
	}

	ACoinGameMode* GameMode = Cast<ACoinGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode == nullptr)
	{
		return;
	}

	Character->ClientPlaySound2D(PickupSound);
	Character->AddScore(10);
	Character->AddPickup();

	if (ItemTypeSpeed == true)
	{
		UitemBuffComponent* ItemBuff = Character->GetitemBuff();
		if (ItemBuff)
		{
			ItemBuff->SpeedBuffProc(BaseSpeedBuff, SpeedBuffTime);
		}
	}
	Destroy();
}

