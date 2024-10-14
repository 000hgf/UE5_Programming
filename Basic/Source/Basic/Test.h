// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test.generated.h"

UCLASS()
class BASIC_API ATest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly)
	int32 EDOVal = 10;
	UPROPERTY(EditInstanceOnly)
	int32 EIOVal = 20;
	UPROPERTY(EditAnywhere)
	int32 EAVal = 30;
	UPROPERTY(VisibleDefaultsOnly)
	int32 VDOVal = 40;
	UPROPERTY(VisibleInstanceOnly)
	int32 VIOVal = 50;
	UPROPERTY(VisibleAnywhere)
	int32 VAVal = 60;

private:
	UPROPERTY(VisibleAnywhere)
	float RunningTime = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	float Amplitude = 0.5f;//진폭

	UPROPERTY(EditInstanceOnly)
	float TimeConstant = 10.f;//sin속도를 가속
};
