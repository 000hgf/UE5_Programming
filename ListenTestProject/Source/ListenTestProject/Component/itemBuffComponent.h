#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "itemBuffComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LISTENTESTPROJECT_API UitemBuffComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class ACoinGameCharacter* CoinGameCharacter;

	FTimerHandle SpeedBuffTimer;


	void ResetSpeed();

	UFUNCTION(NetMulticast,Reliable)
	void MulticastSpeedBuff(float BaseSpeed);

public:	
	friend class ACoinGameCharacter;
	UitemBuffComponent();

	float InitialBaseSpeed;//캐릭터 기본 속도

	void SetInitialSpeed(float BaseSpeed) { InitialBaseSpeed = BaseSpeed; };
	void SpeedBuffProc(float BuffBaseSpeed, float BuffTime);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
