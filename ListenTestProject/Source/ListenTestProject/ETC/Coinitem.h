#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coinitem.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ACoinitem : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoinitem();

//아이템 속성
private:
	UPROPERTY(EditAnywhere)
	bool ItemTypeSpeed = false;
	UPROPERTY(EditAnywhere)
	float BaseSpeedBuff = 1000.f;
	UPROPERTY(EditAnywhere)
	float SpeedBuffTime = 20.f;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	class URotatingMovementComponent* RotatingMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	class USoundBase* PickupSound;

public:	
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
