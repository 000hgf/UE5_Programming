#include "GameFramework/Character.h"
#include "BaseEquippable.h"

UPrimitiveComponent* ABaseEquippable::GetItemMesh()
{
	if (ItemStaticMesh != nullptr)
	{
		UStaticMesh* StaticMesh = ItemStaticMesh->GetStaticMesh();
		if (StaticMesh != nullptr) // 스태틱 메시를 등록했다면
		{
			return ItemStaticMesh;
		}
	}

	if (ItemSkeletalMesh != nullptr)
	{
		return ItemSkeletalMesh;
	}

	return nullptr;
}

void ABaseEquippable::AttachActor(FName SocketName)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (Character != nullptr) // 무기를 소유한 오너가 있으면 소켓에 붙여준다
	{
		FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, true);
		AttachToComponent(Character->GetMesh(), Rules, SocketName);
	}
}

void ABaseEquippable::OnEquipped_Implementation()
{
	IsEquipped = true;
	AttachActor(AttachSocketName);
}

void ABaseEquippable::OnUnEquipped()
{
	SetIsEquipped(false);
}

// Sets default values
ABaseEquippable::ABaseEquippable()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	ItemSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemSkeletalMesh"));
	ItemSkeletalMesh->SetupAttachment(GetRootComponent());

	ItemStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemStaticMesh"));
	ItemStaticMesh->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ABaseEquippable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEquippable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

