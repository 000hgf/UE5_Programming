// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEquippable.generated.h"

UCLASS()
class BASIC_API ABaseEquippable : public AActor
{
	GENERATED_BODY()
	
private:
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* ItemSkeletalMesh;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ItemStaticMesh;

	UFUNCTION(BlueprintPure, Category = ItemMesh)
	UPrimitiveComponent* GetItemMesh();
	UFUNCTION(BlueprintCallable, Category = ItemMesh)
	void AttachActor(FName SocketName);
	UFUNCTION(BlueprintCallable)
	void OnEquipped();
	UFUNCTION(BlueprintCallable)
	void OnUnEquipped();

	UPROPERTY(VisibleDefaultsOnly)
	bool IsEquipped = false;

public:	
	void SetIsEquipped(bool Equip) { IsEquipped = Equip; }
	bool GetIsEquipped() { return IsEquipped; }

	UPROPERTY(BlueprintReadWrite)
	FName AttachSocketName;

protected:
	virtual void BeginPlay() override;

public:	
	ABaseEquippable();
	virtual void Tick(float DeltaTime) override;


};
