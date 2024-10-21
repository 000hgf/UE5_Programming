#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShootingAIController.generated.h"

UCLASS()
class BASIC_API AShootingAIController : public AAIController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* EnemyBT;

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaSeconds) override;

};
