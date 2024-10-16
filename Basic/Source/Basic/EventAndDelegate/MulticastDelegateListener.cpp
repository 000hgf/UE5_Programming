#include "MulticastDelegateListener.h"
#include "../MGameInstance.h"
#include "Components/PointLightComponent.h"

AMulticastDelegateListener::AMulticastDelegateListener()
{
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	SetRootComponent(PointLight);
	PointLight->SetVisibility(false);
}

void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		//멀티캐스트 델리게이트는 핸들 관리를 해줘야한다
		DelegateHandle = MGI->MulticastDelegateSignature.AddUObject(this, &ThisClass::ToggleLight);
	}
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UMGameInstance* MGI = Cast<UMGameInstance>(GetWorld()->GetGameInstance());
	if (MGI != nullptr)
	{
		//핸들을 remove시켜줘야한다
		MGI->MulticastDelegateSignature.Remove(DelegateHandle);
	}
}

void AMulticastDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMulticastDelegateListener::ToggleLight()
{
	PointLight->ToggleVisibility();
}


