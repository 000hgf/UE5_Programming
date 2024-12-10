#pragma once

#include "CoreMinimal.h"
#include "HCharBase.h"
#include "NetworkBasicCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS(config = Game)
class ANetworkBasicCharacter : public AHCharBase
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CommandAction;

public:

	ANetworkBasicCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void RPCCommand(const FInputActionValue& Value);

	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

public:
	UFUNCTION(BlueprintCallable)
	void OpenLevel();
	UFUNCTION(BlueprintCallable)
	void CallOpenLevel(const FString& Address);
	UFUNCTION(BlueprintCallable)
	void CallClientTravel(const FString& Address);

	// 변수의 Replication
protected:
	UPROPERTY(Replicated)
	float R_Health = 100.0f;

	UPROPERTY(ReplicatedUsing = OnRep_Mana)
	int32 RU_Mana;
	UFUNCTION()
	void OnRep_Mana();

	// RPC Command
public:
	UFUNCTION(Server, WithValidation, Reliable)
	void ServerMsgTest(int32 Value);
	UFUNCTION(Client, Unreliable)
	void ClientMsgTest(int32 Value);
	UFUNCTION(Client, Reliable)
	void ClientAliMsgTest(int32 Value);
};