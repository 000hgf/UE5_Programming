// Fill out your copyright notice in the Description page of Project Settings.


#include "MMovingPlatform.h"

// Sets default values
AMMovingPlatform::AMMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STATIC_MESH"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AMMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else 
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	//CurrentRotation = CurrentRotation + (RotationVelocity * DeltaTime);
	//SetActorRotation(CurrentRotation);
	// 피치 회전시 오류 수정 버전
	CurrentRotation = RotationVelocity * DeltaTime;
	AddActorLocalRotation(CurrentRotation);
}

bool AMMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved()>MoveDistance;
}

float AMMovingPlatform::GetDistanceMoved() const
{
	//인자로 넘긴 두 벡터 사이의 거리를 구하는 함수
	return FVector::Dist(StartLocation, GetActorLocation());
}
