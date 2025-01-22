// KeyItem.cpp
#include "HorrorHotel/Public/Items/KeyItem.h"

#include "GameCore/MultiplayerGameStateBase.h"
#include "HorrorHotel/Public/Items/PickableItem.h"


AKeyItem::AKeyItem()
{
	ItemName = TEXT("Key");
}

void AKeyItem::OnPickedUp()
{
	Super::OnPickedUp();

	Server_OnPickedUp();
}

void AKeyItem::Server_OnPickedUp_Implementation()
{
	IncrementKeysCount();
	Destroy();
}

void AKeyItem::IncrementKeysCount()
{
	if (GetWorld())
	{
		AMultiplayerGameStateBase* GameState = GetWorld()->GetGameState<AMultiplayerGameStateBase>();
		if (GameState)
		{
			GameState->Addkey();
		}
	}
}
