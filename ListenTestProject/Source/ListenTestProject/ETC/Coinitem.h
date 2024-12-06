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
