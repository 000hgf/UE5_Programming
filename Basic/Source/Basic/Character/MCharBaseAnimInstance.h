#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MCharBaseAnimInstance.generated.h"

class AMCharBase;
class UCharacterMovementComponent;

UCLASS()
class BASIC_API UMCharBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	AMCharBase* MCharBase;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UCharacterMovementComponent* MCharMovementComponent;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	FVector MCharVelocity;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float MCharSpeed;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool MShouldMove;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool MCharIsFalling;

protected:
	//Event Blueprint Initialize Animation 이벤트
	virtual void NativeInitializeAnimation() override;
	//Event Blueprint Update Animation 이벤트
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
