#pragma once

#include "CoreMinimal.h"
#include "MCharBase.h"
#include "MCharShooting.generated.h"

class ARifle;

UCLASS()
class BASIC_API AMCharShooting : public AMCharBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARifle> RifleClass;
	UPROPERTY()
	ARifle* Rifle;

public:
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_Shoot;
	void Shoot();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
