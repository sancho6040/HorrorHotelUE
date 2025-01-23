// KeyItem.cpp
#include "HorrorHotel/Public/Items/KeyItem.h"
#include "GameCore/MultiplayerGameStateBase.h"
#include "Net/UnrealNetwork.h"


AKeyItem::AKeyItem()
{
	ItemName = TEXT("Key");
}

void AKeyItem::OnInteraction()
{
	Super::OnInteraction();

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
