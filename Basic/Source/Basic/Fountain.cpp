// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	SetRootComponent(Body);

	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Water->SetupAttachment(Body);
	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	//가상경로
	// / Script / Engine.StaticMesh'/Game/EX10_cpp/Fountain/SM_Fountain.SM_Fountain'
	//절 대 실무에서 소스코드에 경로를 박아놓지말것(개박살남)
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BODY(TEXT(" / Game / EX10_cpp / Fountain / SM_Fountain.SM_Fountain"));
	if (SM_BODY.Succeeded())
	{
		Body->SetStaticMesh(SM_BODY.Object);
	}*/

	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	Movement->RotationRate = FRotator(0.0f, 30.0f, 0.0f);
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

