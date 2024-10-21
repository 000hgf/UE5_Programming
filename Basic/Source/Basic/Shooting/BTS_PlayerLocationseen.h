#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_PlayerLocationseen.generated.h"

UCLASS()
class BASIC_API UBTS_PlayerLocationseen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTS_PlayerLocationseen();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
