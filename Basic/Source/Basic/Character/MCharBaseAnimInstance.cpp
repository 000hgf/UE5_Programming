#include "MCharBaseAnimInstance.h"
#include "MCharBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
//애님 인스턴스가 초기화 될때 래퍼런스를 저장
void UMCharBaseAnimInstance::NativeInitializeAnimation()
{
	//캐릭터 래퍼런스 저장
	MCharBase = Cast<AMCharBase>(TryGetPawnOwner());
	if (MCharBase != nullptr)
	{
		MCharMovementComponent = MCharBase->GetCharacterMovement();
	}
}

//애니메이션 업데이트 루프
void UMCharBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (MCharMovementComponent)
	{
		MCharVelocity = MCharMovementComponent->Velocity;
		MCharSpeed = UKismetMathLibrary::VSizeXY(MCharVelocity);

		//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, FString::Printf(TEXT("Speed: %f"), MCharSpeed));
		

		MShouldMove = false;
		bool Acceleration = !MCharMovementComponent->GetCurrentAcceleration().Equals(FVector::ZeroVector,0);
		if (MCharSpeed > 3.0f && Acceleration)
		{
			MShouldMove = true;
		}
		MCharIsFalling = MCharMovementComponent->IsFalling();
	}
}
