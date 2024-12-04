#pragma once

#include "CoreMinimal.h"
#include "Logging/LogMacros.h"
#include "HCharBase.h"
#include "NetworkBasicCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS(config=Game)
class ANetworkBasicCharacter : public AHCharBase
{
	GENERATED_BODY()

public:
	ANetworkBasicCharacter();	
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController);

public:
	UFUNCTION(BlueprintCallable)
	void OpenLevel();
	UFUNCTION(BlueprintCallable)
	void CallOpenLevel(const FString& Address);
	UFUNCTION(BlueprintCallable)
	void CallClientTravel(const FString& Address);

//변수의 Replication
protected:
	UPROPERTY(Replicated)//리플리케이트 선언
	float R_Health = 100.0f;

	UPROPERTY(ReplicatedUsing = OnRep_Mana)
	int32 RU_Mana;

	UFUNCTION()
	void OnRep_Mana();
};