#include "MCharShootingAnimInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "MCharShooting.h"

void UMCharShootingAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MCharBase != nullptr)
	{	
		//앵글 구하기
		FVector ITVector = UKismetMathLibrary::InverseTransformDirection(
			MCharBase->GetActorTransform(), MCharBase->GetVelocity()
		);
		FRotator Rot = UKismetMathLibrary::Conv_VectorToRotator(ITVector);
		Angle = Rot.Yaw;

		//에임 피치
		Rot = UKismetMathLibrary::NormalizedDeltaRotator(MCharBase->GetControlRotation(), MCharBase->GetActorRotation());
		AimPitch = Rot.Pitch;

		//죽었는지 살았는지는 캐릭터에서 Health값 추가 + 계산후 적ㅇ용
		AMCharShooting* MCharShooter = Cast<AMCharShooting>(MCharBase);
		if (MCharShooter != nullptr)
		{
			IsDead = MCharShooter->IsDead();
		}
	}
}
