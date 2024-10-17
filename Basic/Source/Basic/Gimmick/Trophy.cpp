#include "Trophy.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "../MGameInstance.h"

ATrophy::ATrophy()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScenRoot"));
	SetRootComponent(DefaultSceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(GetRootComponent());

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0.0f, 30.f, 0.0f);
}

void ATrophy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATrophy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (StaticMesh)
	{
		//Áß¿ä
		StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapTrophyMesh);
	}
}

void ATrophy::OnOverlapTrophyMesh(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, FString::Printf(TEXT("On Overlap Begin~~ Name %s"), *OtherActor->GetName()));
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UMGameInstance* MGI = Cast<UMGameInstance>(World->GetGameInstance());
		if (MGI != nullptr)
		{
			MGI->DefaultDelegateSignature.ExecuteIfBound();
		}
	}
}

void ATrophy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Amplitude = 6.0f;
	float TimeConstant = 5.0f;
	static float RunningTime = 0.0f;
	
	RunningTime += DeltaTime;
	float DeltaVal = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaVal));
}

