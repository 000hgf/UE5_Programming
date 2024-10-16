#include "EventTrigger.h"
#include "Components/BoxComponent.h"

AEventTrigger::AEventTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->SetBoxExtent(FVector(200,200,200));
}

void AEventTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEventTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEventTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s BeginOverlap"),*(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
	OnEvent1.Broadcast(); //이벤트1 브로드캐스트
}

void AEventTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s EndOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
	OnEvent2.Broadcast();
}

