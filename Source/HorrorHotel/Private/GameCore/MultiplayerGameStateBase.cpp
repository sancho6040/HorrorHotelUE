#include "MultiplayerGameStateBase/MultiplayerGameStateBase.h"
#include "Net/UnrealNetwork.h"

AMultiplayerGameStateBase::AMultiplayerGameStateBase()
{
	KeysCount = 0;
}

void AMultiplayerGameStateBase::Addkey()
{
	if(HasAuthority())
	{
		KeysCount++;
		OnRep_KeyCount();
	}
}

int32 AMultiplayerGameStateBase::GetKeyCount() const
{
	return KeysCount;
}

void AMultiplayerGameStateBase::OnRep_KeyCount()
{
	
}

void AMultiplayerGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMultiplayerGameStateBase, KeysCount);
}
