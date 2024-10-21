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

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100;//
	UPROPERTY(EditAnywhere)
	float Health; //Ã¼·Â

public:
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_Shoot;
	void Shoot();

	UFUNCTION(BlueprintPure)
	bool IsDead() const;
	
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCause) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
