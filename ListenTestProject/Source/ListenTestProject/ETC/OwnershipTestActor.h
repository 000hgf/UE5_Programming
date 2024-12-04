// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OwnershipTestActor.generated.h"

UCLASS()
class LISTENTESTPROJECT_API AOwnershipTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AOwnershipTestActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float OwnershipRadius = 400.f;

public:	
	virtual void Tick(float DeltaTime) override;

	
	
};
