#include "MCharShooting.h"
#include "../Ex_Shooting/Rifle.h"
#include "EnhancedInputComponent.h"

void AMCharShooting::BeginPlay()
{
	Super::BeginPlay();
	//총을 스폰을 시키고 스켈레톤의 소켓에 부착한다.
	Rifle = GetWorld()->SpawnActor<ARifle>(RifleClass);

	if (Rifle != nullptr)
	{
		Rifle->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
		Rifle->SetOwner(this);
	}
}

void AMCharShooting::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//건트리거 액션 세팅
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{	//Looking
		EnhancedInputComponent->BindAction(IA_Shoot, ETriggerEvent::Started, this, &ThisClass::Shoot);
	}
}


void AMCharShooting::Shoot()
{
	if (Rifle!= nullptr)
	{
		//총에서 트리거 처리
		Rifle->PullTrigger();
	}
}