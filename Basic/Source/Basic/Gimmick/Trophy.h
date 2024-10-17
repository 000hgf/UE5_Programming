#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trophy.generated.h"

UCLASS()
class BASIC_API ATrophy : public AActor
{
	GENERATED_BODY()
	
public:
	class USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	class URotatingMovementComponent* RotatingMovement;

public:	
	ATrophy();

protected:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnOverlapTrophyMesh(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	virtual void Tick(float DeltaTime) override;

};
