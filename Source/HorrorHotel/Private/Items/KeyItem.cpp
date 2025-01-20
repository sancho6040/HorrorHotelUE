// KeyItem.cpp
#include "HorrorHotel/Public/Items/KeyItem.h"

#include "GameCore/MultiplayerGameStateBase.h"
#include "HorrorHotel/Public/Items/PickableItem.h"


AKeyItem::AKeyItem()
{
	// Set default values for this actor's properties if necessary
	ItemName = TEXT("Key");
}

void AKeyItem::OnPickedUp()
{
	Super::OnPickedUp();

	// Add key logic here
	AMultiplayerGameStateBase* MyGameState = GetWorld()->GetGameState<AMultiplayerGameStateBase>();
	if (MyGameState)
	{
		MyGameState->Addkey();
	}

	// Destroy the key after it's picked up
	Destroy();
}
