#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateTrigger.generated.h"

UCLASS()
class BASIC_API AMulticastDelegateTrigger : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY()
	class UBoxComponent* TriggerZone;
public:	
	AMulticastDelegateTrigger();

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
