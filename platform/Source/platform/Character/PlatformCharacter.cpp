#include "PlatformCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../ETC/HDebugMacros.h"

APlatformCharacter::APlatformCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(35.f, 60.0f);

	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 900.f;
	GetCharacterMovement()->AirControl = 0.25f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
}

void APlatformCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void APlatformCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlatformCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
	}
}

void APlatformCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
}

void APlatformCharacter::FellOutOfWorld(const UDamageType& DmgType)
{
	Super::FellOutOfWorld(DmgType);
}