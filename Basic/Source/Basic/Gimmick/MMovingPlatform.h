// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MMovingPlatform.generated.h"

UCLASS()
class BASIC_API AMMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;

private:
	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector PlatformVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere, Category = "Moving")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

public:	
	// Sets default values for this actor's properties
	AMMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
