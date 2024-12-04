// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetworkBasicGameMode.generated.h"

UCLASS(minimalapi)
class ANetworkBasicGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANetworkBasicGameMode();

public:
	// 로그인 관련 3가지 주요 함수 + 게임 시작
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer);
	virtual void StartPlay();
};