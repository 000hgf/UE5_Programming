#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MCollisionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASIC_API UMCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMCollisionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	bool IsCollisionEnabled = false;
	TArray<AActor*> AlreadyHitActors = {};

	TArray<AActor*> ActorToIgnore = {};

	TObjectPtr<UPrimitiveComponent> CollisionMeshComponent;

	UPROPERTY(EditAnywhere)
	FName StartSocketName;
	UPROPERTY(EditAnywhere)
	FName EndSocketName;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	float TraceRadius;

	FHitResult LastHit;

public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void EnableCollision();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DisableCollision();
	
	void ClearHitActors();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetCollisionMesh();
	void CollisionTrace();
};
