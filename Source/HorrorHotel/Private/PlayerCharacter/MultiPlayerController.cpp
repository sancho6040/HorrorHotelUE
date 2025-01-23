//MultiPlayerController.cpp
#include "HorrorHotel/Public/PlayerCharacter/MultiPlayerController.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "Items/KeyItem.h"
#include "Items/PickableItem.h"

AMultiPlayerController::AMultiPlayerController()
{
	// Add UI component
	PlayerUIManagerComponent = CreateDefaultSubobject<UPlayerUIManagerComponent>(TEXT("PlayerUIManagerComponent"));
}

void AMultiPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerUIManagerComponent && IsLocalController())
	{
		PlayerUIManagerComponent->InitializeUI(this);
	}
}

void AMultiPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(SetInteractAction, ETriggerEvent::Started, this,
		                                   &AMultiPlayerController::OnInteract);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component!"), *GetNameSafe(this));
	}
}

void AMultiPlayerController::OnInteract()
{
	if (!ItemToInteract) return;

	if (APickableItem* PickableItem = Cast<APickableItem>(ItemToInteract))
	{
		PickableItem->ItemPickedUpEvent();
	}

	if (IsLocalController())
	{
		Server_PlayerInteract(ItemToInteract);
	}
}

void AMultiPlayerController::Server_PlayerInteract_Implementation(AInteractableItem* InItem)
{
	if (InItem)
	{
		InItem->OnInteraction();
	}
}

void AMultiPlayerController::ShowInteractionWidget(bool bShow)
{
	if (PlayerUIManagerComponent)
	{
		PlayerUIManagerComponent->ShowInteractionWidget(bShow);
	}
}

void AMultiPlayerController::SetInteractionItem(AInteractableItem* InItem)
{
	ItemToInteract = InItem;
}

void AMultiPlayerController::DropItem(int32 ItemIndex)
{
	if (IsLocalController())
	{
		APawn* LocalPawn = GetPawn();
		if (LocalPawn)
		{
			FVector SpawnPosition = LocalPawn->GetActorLocation();
			Server_DropItem(ItemIndex, SpawnPosition);
		}
	}
}

void AMultiPlayerController::Server_DropItem_Implementation(int32 ItemIndex, FVector InLocation)
{
	if (BP_PickableItemClass != nullptr)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		APickableItem* SpawnedItem = GetWorld()->SpawnActor<APickableItem>(
			BP_PickableItemClass, InLocation, FRotator::ZeroRotator, SpawnParams);
		if (SpawnedItem)
		{
			SpawnedItem->ItemIndex = ItemIndex;
		}
	}
}
