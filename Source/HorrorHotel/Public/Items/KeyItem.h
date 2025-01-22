// KeyItem.h
#pragma once

#include "CoreMinimal.h"
#include "PickableItem.h"
#include "KeyItem.generated.h"

UCLASS()
class HORRORHOTEL_API AKeyItem : public APickableItem
{
	GENERATED_BODY()

public:
	AKeyItem();

	virtual void OnPickedUp() override;

protected:
	//Interact RPC
	UFUNCTION(Server, Reliable)
	void Server_OnPickedUp();

	void IncrementKeysCount();
};
