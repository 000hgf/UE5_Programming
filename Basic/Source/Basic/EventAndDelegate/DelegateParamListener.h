#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateParamListener.generated.h"

UCLASS()
class BASIC_API ADelegateParamListener : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	class USpotLightComponent* SpotLight;

private:
	int32 RotateSpeed;

public:
	int32 GetRotateSpeed() { return RotateSpeed; }
	void SetRotateSpeed(int32 Speed) { RotateSpeed = Speed; }

	UFUNCTION()
	void SetLightColor(FLinearColor LightColor);
	UFUNCTION()
	void SetLightColorAndRotate(FLinearColor LightColor, int32 Speed);

public:	
	ADelegateParamListener();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
