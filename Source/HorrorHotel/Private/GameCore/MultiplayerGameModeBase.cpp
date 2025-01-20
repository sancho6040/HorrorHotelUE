#include "MultiplayerGameModeBase.h"

#include "HorrorHotel/MultiPlayerController/MultiPlayerController.h"

AMultiPlayerGameModeBase::AMultiPlayerGameModeBase()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMultiPlayerController::StaticClass();

}
