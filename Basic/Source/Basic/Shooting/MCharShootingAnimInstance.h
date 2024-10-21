#pragma once

#include "CoreMinimal.h"
#include "MCharBaseAnimInstance.h"
#include "MCharShootingAnimInstance.generated.h"

UCLASS()
class BASIC_API UMCharShootingAnimInstance : public UMCharBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly , Category = AO)
	float Angle = 0.0f;
	UPROPERTY(BlueprintReadOnly, Category = AO)
	float AimPitch = 0.0f;
	UPROPERTY(BlueprintReadOnly, Category = Shooter)
	bool IsDead = false;

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
