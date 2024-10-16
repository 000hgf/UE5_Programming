#include "EventListener.h"
#include "EventTrigger.h"

AEventListener::AEventListener()
{
	PrimaryActorTick.bCanEverTick = true;

	EventTriggerObj = nullptr;
	IsRotationState = false; //정지상태
	
	TestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TestMesh"));
	SetRootComponent(TestMesh);
}

void AEventListener::BeginPlay()
{
	Super::BeginPlay();
	
	if (EventTriggerObj != nullptr)
	{
		EventTriggerObj->OnEvent1.AddUObject(this, &ThisClass::OnEvent1Triggered); //ThisClass와 AEventListener는 같다
		EventTriggerObj->OnEvent2.AddUObject(this, &ThisClass::OnEvent2Triggered);

	}
}

void AEventListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetIsRotationState() == true)
	{
		//초당 100도씩 yaw 회전
		static const int32 RotateSpeed = 100;
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed*DeltaTime, 0.0f));
	}
}

void AEventListener::OnEvent1Triggered()
{
	SetIsRotationState(true);
}

void AEventListener::OnEvent2Triggered()
{
	SetIsRotationState(false);
}
