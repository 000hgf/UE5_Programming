#include "OwnershipTestActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../Character/NetworkBasicCharacter.h"
// Sets default values
AOwnershipTestActor::AOwnershipTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	bReplicates = true;

}

// Called when the game starts or when spawned
void AOwnershipTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOwnershipTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), OwnershipRadius, 32, FColor::Yellow);

	if (HasAuthority())
	{
		AActor* NextOwner = nullptr;
		float MinDistacne = OwnershipRadius;
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(this, ANetworkBasicCharacter::StaticClass(), Actors);
		for (AActor* Actor : Actors)
		{
			const float Distance = GetDistanceTo(Actor);
			if (Distance <= MinDistacne)
			{
				MinDistacne = Distance;
				NextOwner = Actor;
			}
		}
		if (GetOwner() != NextOwner)
		{
			SetOwner(NextOwner);
		}
	}
	const FString OwnerString = GetOwner() != nullptr ? GetOwner()->GetName() : TEXT("No Onwer");
	const FString ConnectionString = GetNetConnection() != nullptr ? TEXT("Valid Connection") : TEXT("Not Connected");

	const FString Values = FString::Printf(TEXT("Owner = %s, Connection = %s"),*OwnerString,*ConnectionString);

	DrawDebugString(GetWorld(), GetActorLocation(), Values, nullptr, FColor::White, 0.0f, true);
}

