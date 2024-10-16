#include "DelegateParamListener.h"
#include "../MGameInstance.h"
#include "Components/SpotLightComponent.h"

ADelegateParamListener::ADelegateParamListener()
{
	PrimaryActorTick.bCanEverTick = true;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Spotlight"));
	SetRootComponent(SpotLight);
	SpotLight->SetIntensity(100000.f);
	RotateSpeed = 0;
}

void ADelegateParamListener::BeginPlay()
{
	Super::BeginPlay();
	
	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		//델리게이트 바인딩
		MGI->DefaultDelegateSignatureParam1.BindUObject(this, &ThisClass::SetLightColor);
		MGI->DefaultDelegateSignatureParam2.BindUObject(this, &ThisClass::SetLightColorAndRotate);
	}
}

void ADelegateParamListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetRotateSpeed() >= 0)//스피드 값이 설정된 상태
	{
		//초당 설정된 각도로 yaw 회전
		AddActorLocalRotation(FRotator(0.0f, GetRotateSpeed() * DeltaTime, 0.0f));
	}
}

void ADelegateParamListener::SetLightColor(FLinearColor LightColor)
{
	SpotLight->SetLightColor(LightColor);
	SetRotateSpeed(0);
}

void ADelegateParamListener::SetLightColorAndRotate(FLinearColor LightColor, int32 Speed)
{
	SpotLight->SetLightColor(LightColor);
	SetRotateSpeed(Speed);
}
