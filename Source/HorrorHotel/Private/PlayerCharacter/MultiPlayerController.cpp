#include "HorrorHotel/Public/PlayerCharacter/MultiPlayerController.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameCore/MultiplayerGameStateBase.h"
#include "Items/KeyItem.h"
#include "PlayerCharacter/MultiPlayerState.h"

AMultiPlayerController::AMultiPlayerController()
{
	// Add UI component
	PlayerUIManagerComponent = CreateDefaultSubobject<UPlayerUIManagerComponent>(TEXT("PlayerUIManagerComponent"));
}

void AMultiPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerUIManagerComponent)
	{
		PlayerUIManagerComponent->InitializeUI(this);
	}
}

void AMultiPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(SetInteractAction, ETriggerEvent::Started, this, &AMultiPlayerController::OnInteract);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AMultiPlayerController::OnInteract()
{
	if(ItemToInteract)
	{
		ItemToInteract->OnPickedUp();
	}
}

void AMultiPlayerController::ShowInteractionWidget(bool bShow)
{
	if (PlayerUIManagerComponent)
	{
		PlayerUIManagerComponent->ShowInteractionWidget(bShow);
	}
}

void AMultiPlayerController::SetInteractionItem(APickableItem* InItem)
{
	ItemToInteract = InItem;
}
