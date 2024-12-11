#include "MCollisionComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UMCollisionComponent::UMCollisionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery1);
}


void UMCollisionComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UMCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsCollisionEnabled)
	{
		CollisionTrace();
	}
}

void UMCollisionComponent::EnableCollision_Implementation()
{
}

void UMCollisionComponent::DisableCollision_Implementation()
{
}

void UMCollisionComponent::ClearHitActors()
{
	AlreadyHitActors.Empty();
	AlreadyHitActors.Add(GetOwner());
}

void UMCollisionComponent::SetCollisionMesh_Implementation()
{
	//CollisionMeshComponent = MeshComponent;
}

void UMCollisionComponent::CollisionTrace()
{
	if (CollisionMeshComponent == nullptr)
	{
		return;
	}

	TArray<FHitResult>IgnoredActors = {};

	bool Hit = UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(),
		CollisionMeshComponent->GetSocketLocation(StartSocketName),
		CollisionMeshComponent->GetSocketLocation(EndSocketName),
		TraceRadius,
		ObjectTypes,
		false,
		AlreadyHitActors,
		EDrawDebugTrace::ForOneFrame,
		IgnoredActors,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		5.0f
	);

	if (Hit)
	{
		for (const FHitResult& Result : IgnoredActors)
		{
			AActor* HitActor = Result.GetActor();
			if (HitActor && !AlreadyHitActors.Contains(HitActor))
			{
				// AlreadyHitActors¿¡ Ãß°¡
				AlreadyHitActors.Add(HitActor);
			}
		}
	}
}

