#include "MulticastDelegateParamTrigger.h"
#include "../MGameInstance.h"
#include "Components/BoxComponent.h"

// Sets default values
AMulticastDelegateParamTrigger::AMulticastDelegateParamTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->SetBoxExtent(FVector(200, 200, 200));
}

void AMulticastDelegateParamTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMulticastDelegateParamTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMulticastDelegateParamTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s EndOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UMGameInstance* MGI = Cast<UMGameInstance>(World->GetGameInstance());
		if (MGI != nullptr)
		{
			//델리게이트 호출시 파라미터 1개를 전달
			MGI->MulticastDelegateSignature1.Broadcast(LightColor);
		}
	}
}

void AMulticastDelegateParamTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s EndOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UMGameInstance* MGI = Cast<UMGameInstance>(World->GetGameInstance());
		if (MGI != nullptr)
		{
			MGI->MulticastDelegateSignature2.Broadcast(FLinearColor(1.0f, 0.0f, 0.f), RotateSpeed);
		}
	}
}