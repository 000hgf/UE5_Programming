#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MulticastDelegateParamListener.generated.h"

UCLASS()
class BASIC_API AMulticastDelegateParamListener : public AActor
{
	GENERATED_BODY()

public:
	FDelegateHandle DelegateHandle1;
	FDelegateHandle DelegateHandle2;

public:
	UPROPERTY()
	class USpotLightComponent* SpotLight;

private:
	int32 RotateSpeed;

public:
	int32 GetRotateSpeed() { return RotateSpeed; }
	void SetRotateSpeed(int32 Speed) { RotateSpeed = Speed; }

public:
	void SetLightColor(FLinearColor LightColor);
	void SetLightColorAndRotate(FLinearColor LightColor, int32 Speed);
public:	
	AMulticastDelegateParamListener();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	virtual void Tick(float DeltaTime) override;
};
