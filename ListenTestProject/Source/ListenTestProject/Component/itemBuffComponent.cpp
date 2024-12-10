#include "itemBuffComponent.h"
#include "../Character/CoinGameCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UitemBuffComponent::ResetSpeed()
{
	if (CoinGameCharacter == nullptr|| CoinGameCharacter->GetCharacterMovement()==nullptr)
	{
		return;
	}
	//원래 대로
	CoinGameCharacter->GetCharacterMovement()->MaxWalkSpeed = InitialBaseSpeed;
	MulticastSpeedBuff(InitialBaseSpeed);
}

void UitemBuffComponent::MulticastSpeedBuff_Implementation(float BaseSpeed)
{
	if (CoinGameCharacter && CoinGameCharacter->GetCharacterMovement())
	{
		CoinGameCharacter->GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
	}
}

void UitemBuffComponent::SpeedBuffProc(float BuffBaseSpeed, float BuffTime)
{
	if (CoinGameCharacter == nullptr)
	{
		return;
	}

	CoinGameCharacter->GetWorldTimerManager().SetTimer(SpeedBuffTimer, this, &ThisClass::ResetSpeed, BuffTime);
	if (CoinGameCharacter == nullptr)
	{
		CoinGameCharacter->GetCharacterMovement()->MaxWalkSpeed = BuffBaseSpeed;
	}
	MulticastSpeedBuff(BuffBaseSpeed);
}

UitemBuffComponent::UitemBuffComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UitemBuffComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UitemBuffComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

