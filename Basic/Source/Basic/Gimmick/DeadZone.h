#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeadZone.generated.h"

UCLASS()
class BASIC_API ADeadZone : public AActor
{
	GENERATED_BODY()
	
public:	
	ADeadZone();

	class USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	class USkeletalMeshComponent* Ragdoll;

protected:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnOverlapDeadZoneMesh(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	virtual void Tick(float DeltaTime) override;

};
