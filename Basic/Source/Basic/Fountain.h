// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

//class UStaticMeshComponent;//전방선언 순환참조를 예방하기 좋다
//class URotatingMovementComponent

UCLASS()
class BASIC_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
	//변수 선언과 동시에 전방선언
	class UStaticMeshComponent* Body;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Water;
	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* Light;
	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* Splash;
	UPROPERTY(VisibleAnywhere)
	class URotatingMovementComponent* Movement;

public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
