#include "DelegateParamTrigger.h"
#include "../MGameInstance.h"
#include "Components/CapsuleComponent.h"

ADelegateParamTrigger::ADelegateParamTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TriggerZone"));
	TriggerZone->InitCapsuleSize(200.f,350.f);
	LightColor = FLinearColor(1, 1, 1, 1);//흰색
	RotateSpeed = 0;
}

void ADelegateParamTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADelegateParamTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateParamTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s BeginOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UMGameInstance* MGI = Cast<UMGameInstance>(World->GetGameInstance());
		if (MGI != nullptr)
		{	
			//델리게이트 호출시 파라미터 1개를 전달
			MGI->DefaultDelegateSignatureParam1.ExecuteIfBound(LightColor);
		}
	}
}

void ADelegateParamTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT(" %s EndOverlap"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UMGameInstance* MGI = Cast<UMGameInstance>(World->GetGameInstance());
		if (MGI != nullptr)
		{
			MGI->DefaultDelegateSignatureParam2.ExecuteIfBound(FLinearColor(1.0f,0.0f,0.f),RotateSpeed);
		}
	}
}

