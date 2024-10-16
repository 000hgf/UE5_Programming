#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateListener.generated.h"

UCLASS()
class BASIC_API ADelegateListener : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	class UPointLightComponent* PointLight;

public:	
	ADelegateListener();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UFUNCTION()
	void EnableLight();

public:	
	virtual void Tick(float DeltaTime) override;

};
