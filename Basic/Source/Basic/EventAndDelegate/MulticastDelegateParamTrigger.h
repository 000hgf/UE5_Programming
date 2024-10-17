#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateParamTrigger.generated.h"

UCLASS()
class BASIC_API AMulticastDelegateParamTrigger : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UFUNCTION()
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UPROPERTY()
	class UBoxComponent* TriggerZone;
	UPROPERTY(EditAnywhere)
	FLinearColor LightColor;
	UPROPERTY(EditAnywhere)
	int32 RotateSpeed;

public:	
	AMulticastDelegateParamTrigger();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
