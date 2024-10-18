#pragma once

#include "CoreMinimal.h"
#include "MCharBase.h"
#include "MCharPlatform.generated.h"

UCLASS()
class BASIC_API AMCharPlatform : public AMCharBase
{
	GENERATED_BODY()
public:
	AMCharPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	FDelegateHandle DelegateHandle;

	UFUNCTION()
	void SetGameEvent(int32 Type);
};
