#include "NetworkBasicCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "../ETC/HDebugMacros.h"
#include "Net/UnrealNetwork.h"


ANetworkBasicCharacter::ANetworkBasicCharacter()
{
	// Set size for collision capsule
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

void ANetworkBasicCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ANetworkBasicCharacter::PossessedBy(AController* NewController)
{
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("Begin"));
	Super::PossessedBy(NewController);
	HLOG_NET_LOG(Log, TEXT("%s"), TEXT("End"));

}

void ANetworkBasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FString LocalRoleString = ROLE_TO_STRING(GetLocalRole());
	const FString RemoteRoleString = ROLE_TO_STRING(GetRemoteRole());

	const AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	const AGameStateBase* GameState = GetWorld()->GetGameState();
	const APlayerController* PlayerController = Cast<APlayerController>(GetController());
	const AHUD* HUD = PlayerController != nullptr ? PlayerController->GetHUD() : nullptr;

	const FString GameModeString = GameMode != nullptr ? TEXT("Valid") : TEXT("InValid");
	const FString GameStateString = GameState != nullptr ? TEXT("Valid") : TEXT("InValid");
	const FString PlayerStateString = GetPlayerState() != nullptr ? TEXT("Valid") : TEXT("InValid");
	const FString PawnName = GetName();
	const FString ControllerString = PlayerController != nullptr ? TEXT("Valid") : TEXT("InValid");
	const FString HUDString = HUD != nullptr ? TEXT("Valid") : TEXT("InValid");

	FString Values = FString::Printf(TEXT("LocalRole = %s\nRemoteRole = %s\nGameMode = %s\nGameState = %s\nPlayerState = %s\nPawnName = %s\nController = %s\nHUD = %s"), *LocalRoleString, *RemoteRoleString, *GameModeString, *GameStateString, *PlayerStateString
		,*PawnName, *ControllerString, *HUDString);

	if (HasAuthority())
	{
		R_Health += 1.0f;
		RU_Mana++;

		FString str = FString::Printf(TEXT("[%s] to Add"), *LocalRoleString);
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, *str);
	}

	FString Values2 = FString::Printf(TEXT("\n\nHealth: %.2f/ Mana = %d"),R_Health,RU_Mana);
	Values.Append(Values2);

	DrawDebugString(GetWorld(), GetActorLocation(), Values, nullptr, FColor::White, 0.0f, true);
}

void ANetworkBasicCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const //헤더에 선언하지 않아도 Replicated를 선언하면 자동으로 생성되는 함수
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANetworkBasicCharacter, R_Health);//추가 복제 조건없이 다음 매크로를 사용하여 리플리케이션

	DOREPLIFETIME_CONDITION(ANetworkBasicCharacter, RU_Mana, COND_OwnerOnly);//복제조건을 명시하여 리플리케이션(COND_OwnerOnly는 이 액터의
																				//Owner에게만 리플리케이션 하라는 플래그)
}

//서버가 클라이언트의 RU_Mana를 업데이트 할때마다 호출
void ANetworkBasicCharacter::OnRep_Mana()
{
	const FString String = FString::Printf(TEXT("Changed current Mana %d"), RU_Mana);
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Blue, String);
}


void ANetworkBasicCharacter::OpenLevel()
{
	UWorld* World = GetWorld();
	if (World)
	{
		World->ServerTravel("/Game/ThirdPerson/Maps/L_Lobby?listen");
	}
}

void ANetworkBasicCharacter::CallOpenLevel(const FString& Address)
{
	UGameplayStatics::OpenLevel(this, *Address);
}

void ANetworkBasicCharacter::CallClientTravel(const FString& Address)
{
	APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if (PlayerController)
	{
		PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}

void ANetworkBasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 나중에 추가되는 입력만 처리
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
	}
}