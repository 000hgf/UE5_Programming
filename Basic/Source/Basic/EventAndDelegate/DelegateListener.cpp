#include "../MGameInstance.h"
#include "DelegateListener.h"
#include "Components/PointLightComponent.h"

ADelegateListener::ADelegateListener()
{
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	SetRootComponent(PointLight);
	PointLight->SetVisibility(false);
	PointLight->SetLightColor(FLinearColor::Blue);
	PointLight->SetIntensity(10000);
}

void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		//델리게이트 바인딩
		MGI->DefaultDelegateSignature.BindUObject(this, &ThisClass::EnableLight);
	}
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		//소멸시 바인딩 해제 필수!
		MGI->DefaultDelegateSignature.Unbind();
	}
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(true);
}

void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

