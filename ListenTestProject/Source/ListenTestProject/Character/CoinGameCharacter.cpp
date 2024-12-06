#include "CoinGameCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/GameMode.h"
#include "../CoinFramework/CoinPlayerState.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

ACoinGameCharacter::ACoinGameCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
}

void ACoinGameCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ACoinGameCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), FallSound);
	}
}

void ACoinGameCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	
	UGameplayStatics::PlaySound2D(GetWorld(), LandSound);
}

void ACoinGameCharacter::FellOutOfWorld(const UDamageType& dmgType)
{
	AController* BackupController = Controller;

	AddScore(-10);
	Destroy();

	AGameMode* GameMode = GetWorld()->GetAuthGameMode<AGameMode>();
	if (GameMode)
	{
		GameMode->RestartPlayer(BackupController);
	}
}

//기본점수에 Score를 + 시키는 함수
void ACoinGameCharacter::AddScore(const float Score) const
{
	APlayerState* MyPlayerState = GetPlayerState();
	if (MyPlayerState != nullptr)
	{
		const float CurrentScore = MyPlayerState->GetScore();
		MyPlayerState->SetScore(CurrentScore + Score);
	}
}

//플레이어 스테이트에 리플리케이션 호출
void ACoinGameCharacter::AddPickup() const
{
	ACoinPlayerState* MyPlayerState = GetPlayerState<ACoinPlayerState>();
	if (MyPlayerState)
	{
		MyPlayerState->AddPickup();
	}
}

//RPC함수 호출
void ACoinGameCharacter::ClientPlaySound2D_Implementation(USoundBase* Sound)
{
	UGameplayStatics::PlaySound2D(GetWorld(), Sound);
}


