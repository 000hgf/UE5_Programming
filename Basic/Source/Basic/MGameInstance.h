
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EventAndDelegate/MDelegateDefine.h"
#include "MGameInstance.generated.h"

UCLASS()
class BASIC_API UMGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	FDelegateSignature DefaultDelegateSignature;
	FDelegateSignatureParam1 DefaultDelegateSignatureParam1;
	FDelegateSignatureParam2 DefaultDelegateSignatureParam2;
		
	FMulticastDelegateSignature MulticastDelegateSignature;
	FMulticastDelegateSignature1 MulticastDelegateSignature1;
	FMulticastDelegateSignature2 MulticastDelegateSignature2;

	FMDSignature1 MD_GameEnd;

};
