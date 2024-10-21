#include "MCharShooting.h"
#include "../Ex_Shooting/Rifle.h"
#include "EnhancedInputComponent.h"
#include "../DebugMacros.h"

void AMCharShooting::BeginPlay()
{
	Super::BeginPlay();
	//총을 스폰을 시키고 스켈레톤의 소켓에 부착한다.
	Health = MaxHealth;

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

bool AMCharShooting::IsDead() const
{
	return Health <= 0;
}

float AMCharShooting::GetHealthPercent() const
{
	if (MaxHealth >= 0)
	{
		return Health / MaxHealth;
	}
	return 0.0f;
}

float AMCharShooting::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCause)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCause);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply; //Health는 0밑으로 떨어지지않는다.
	HLOG(Warning, TEXT("Health: %f/%f"), Health, MaxHealth);
	return 0.0f;
}