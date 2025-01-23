#include "HorrorHotel/Public/GameCore/MultiplayerGameModeBase.h"

#include "HorrorHotel/Public/PlayerCharacter/MultiPlayerController.h"

AMultiPlayerGameModeBase::AMultiPlayerGameModeBase()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMultiPlayerController::StaticClass();

}
