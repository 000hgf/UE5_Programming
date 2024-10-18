#include "DeadZone.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "../MGameInstance.h"

ADeadZone::ADeadZone()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScenRoot"));
	SetRootComponent(DefaultSceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(GetRootComponent());
}

void ADeadZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADeadZone::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (StaticMesh)
	{
		//Áß¿ä
		StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapDeadZoneMesh);
	}
}

void ADeadZone::OnOverlapDeadZoneMesh(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You Died: Name %s"), *OtherActor->GetName()));
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UMGameInstance* MGI = Cast<UMGameInstance>(World->GetGameInstance());
		if (MGI != nullptr)
		{
			MGI->MD_GameEnd.Broadcast(0);
		}
	}
}

void ADeadZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

