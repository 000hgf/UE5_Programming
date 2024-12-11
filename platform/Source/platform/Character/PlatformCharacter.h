#pragma once

#include "CoreMinimal.h"
#include "HCharBase.h"
#include "PlatformCharacter.generated.h"


UCLASS()
class PLATFORM_API APlatformCharacter : public AHCharBase
{
	GENERATED_BODY()
	
public:
	APlatformCharacter();
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void 
	virtual void Landed(const FHitResult& Hit);
	virtual void FellOutOfWorld(const UDamageType& DmgType) override;
};