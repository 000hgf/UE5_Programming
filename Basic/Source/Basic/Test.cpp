// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"
#include "DebugMacros.h"

// Sets default values
ATest::ATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATest::BeginPlay()
{
	Super::BeginPlay();

	/*FVector Location = GetActorLocation();
	MDRAW_SPHERE(Location);

	FVector StartLocation, EndLocation;
	StartLocation = Location;
	EndLocation = StartLocation + (GetActorForwardVector() * 1000);
	MDRAW_VECTOR(StartLocation, EndLocation);*/
}

// Called every frame
void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float DeltaVal = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	AddActorWorldOffset(FVector(0.f, DeltaVal, 0.f));

	FVector Location = GetActorLocation();
	MDRAW_SPHERE_SingleFrame(Location);
	MDRAW_VECTOR_SingleFrame(Location,Location+(GetActorForwardVector())*100.f);
}

