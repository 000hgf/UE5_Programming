#include "Rifle.h"
#include "Kismet/GameplayStatics.h"
#include "../DebugMacros.h"
#include "Engine/DamageEvents.h"
#include "ShootingPlayerController.h"

ARifle::ARifle()
{
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	Mesh->SetupAttachment(Root);
}

void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARifle::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,Mesh,TEXT("MuzzleFlash"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlash"));

	FHitResult Hit;
	FVector ShotDirection;
	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);

		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr)
		{
			//데미지 산출 공식(어디 맞았나)생략
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			AController* OwnerController = GetOwnerController();

			if (AShootingPlayerController* PlayerController = Cast<AShootingPlayerController>(OwnerController))
			{
				HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
			}
			else
			{
				HitActor->TakeDamage((Damage/2), DamageEvent, OwnerController, this);
			}
		}
	}
}

//뷰포트의 로케이션과 로테이션
bool ARifle::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	//총알을 날리기 => 라인트레이스 써야함.
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)
	{
		return false;
	}

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();

	//Shooting을 한게 플레이어냐 Ai냐
	if (AShootingPlayerController* PlayerController = Cast<AShootingPlayerController>(OwnerController))
	{
		//캐스팅 성공시 플레이어
		if (Mesh != nullptr)
		{
			Location = Mesh->GetSocketLocation(TEXT("MuzzleFlash"));
		}
	}
	FVector End = Location + Rotation.Vector() * MaxRange;

	//DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);
	//MDRAW_VECTOR(Location, End);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* ARifle::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
	{
		return nullptr;
	}
	return OwnerPawn->GetController();
}

