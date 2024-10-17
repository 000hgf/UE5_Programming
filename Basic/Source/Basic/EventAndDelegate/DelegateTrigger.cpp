#include "DelegateTrigger.h"
#include "../MGameInstance.h"
#include "Components/SphereComponent.h"

ADelegateTrigger::ADelegateTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerZone"));
	TriggerZone->InitSphereRadius(400.f);
}

void ADelegateTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADelegateTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s BeginOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
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

void ADelegateTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s EndOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
}