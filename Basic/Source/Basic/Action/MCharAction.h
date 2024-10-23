#pragma once

#include "CoreMinimal.h"
#include "Character/MCharBase.h"
#include "MCharAction.generated.h"

UCLASS()
class BASIC_API AMCharAction : public AMCharBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
