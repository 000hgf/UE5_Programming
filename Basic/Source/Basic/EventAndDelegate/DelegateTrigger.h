#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateTrigger.generated.h"

UCLASS()
class BASIC_API ADelegateTrigger : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	class USphereComponent* TriggerZone;
public:	
	ADelegateTrigger();

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
