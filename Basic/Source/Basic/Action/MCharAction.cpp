#include "MCharAction.h"
#include "EnhancedInputComponent.h"

void AMCharAction::BeginPlay()
{
	Super::BeginPlay();

}

void AMCharAction::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Looking
//		EnhancedInputComponent->BindAction(IA_Shoot, ETriggerEvent::Started, this, &ThisClass::Shoot);
	}
}
