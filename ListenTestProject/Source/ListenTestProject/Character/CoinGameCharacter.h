#pragma once

#include "CoreMinimal.h"
#include "HCharBase.h"
#include "CoinGameCharacter.generated.h"

UCLASS()
class LISTENTESTPROJECT_API ACoinGameCharacter : public AHCharBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	class UitemBuffComponent* ItemBuff;
public:
	ACoinGameCharacter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
	class USoundBase* FallSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
	class USoundBase* LandSound;

	FORCEINLINE UitemBuffComponent* GetitemBuff() const { return ItemBuff; };

	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
	virtual void Landed(const FHitResult& Hit) override;
	virtual void FellOutOfWorld(const class UDamageType& dmgType);
public:
	void AddScore(const float Score) const;
	void AddPickup() const;
	//RPC(Remote Procedure Call)
	UFUNCTION(Client, Unreliable)
	void ClientPlaySound2D(USoundBase* Sound);
};
