#include "Items/InteractableDoor.h"

#include "GameCore/MultiplayerGameStateBase.h"

AInteractableDoor::AInteractableDoor()
{
	ItemName = "Door";
}

void AInteractableDoor::OnInteraction()
{
	Super::OnInteraction();

	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("door interaction"));
	
	if(AMultiplayerGameStateBase* GameState = GetWorld()->GetGameState<AMultiplayerGameStateBase>())
	{

		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Door Game State"));
		
		int32 CurrentKeys = GameState->GetKeyCount();
		int32 MaxKeys = GameState->GetMaxKeys();

		if(CurrentKeys >= MaxKeys)
		{
			OpenDoorEvent();
		}
		else
		{
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Find the all the keys to open the door."));
		}
	}
}
