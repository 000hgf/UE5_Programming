#include "Coinitem.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Sound/SoundBase.h"
#include "../Character/CoinGameCharacter.h"
#include "../CoinFramework/CoinGameState.h"

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

	if(Character == nullptr || !HasAuthority())
	{
		return;
	}

	ACoinGameState* GameState = Cast<ACoinGameState>(GetWorld()->GetGameState());
	if (GameState!=nullptr)
	{
		GameState->RemovePickup();
	}

	Character->ClientPlaySound2D(PickupSound);
	Character->AddScore(10);
	Character->AddPickup();
	Destroy();
}

