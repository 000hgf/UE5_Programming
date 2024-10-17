#include "MulticastDelegateParamListener.h"
#include "../MGameInstance.h"
#include "Components/SpotLightComponent.h"	


AMulticastDelegateParamListener::AMulticastDelegateParamListener()
{
	PrimaryActorTick.bCanEverTick = true;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SetRootComponent(SpotLight);
	SpotLight->SetIntensity(10000.f);

	RotateSpeed = 0;
}

void AMulticastDelegateParamListener::BeginPlay()
{
	Super::BeginPlay();
	
	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		DelegateHandle1 = MGI->MulticastDelegateSignature1.AddUObject(this, &ThisClass::SetLightColor);
		DelegateHandle2 = MGI->MulticastDelegateSignature2.AddUObject(this, &ThisClass::SetLightColorAndRotate);
	}
}

void AMulticastDelegateParamListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetRotateSpeed() >= 0)//스피드 값이 설정된 상태
	{
		//초당 설정된 각도로 yaw 회전
		AddActorLocalRotation(FRotator(0.0f, GetRotateSpeed() * DeltaTime, 0.0f));
	}
}


void AMulticastDelegateParamListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		MGI->MulticastDelegateSignature1.Remove(DelegateHandle1);
		MGI->MulticastDelegateSignature2.Remove(DelegateHandle2);
	}
}

void AMulticastDelegateParamListener::SetLightColor(FLinearColor LightColor)
{
	SpotLight->SetLightColor(LightColor);
	SetRotateSpeed(0);
}

void AMulticastDelegateParamListener::SetLightColorAndRotate(FLinearColor LightColor, int32 Speed)
{
	SpotLight->SetLightColor(LightColor);
	SetRotateSpeed(Speed);
}
