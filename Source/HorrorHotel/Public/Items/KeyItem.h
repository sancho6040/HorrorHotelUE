// KeyItem.h
#pragma once

#include "CoreMinimal.h"
#include "InteractableItem.h"
#include "KeyItem.generated.h"

UCLASS()
class HORRORHOTEL_API AKeyItem : public AInteractableItem
{
	GENERATED_BODY()

public:
	AKeyItem();

	virtual void OnInteraction() override;

protected:
	
	void IncrementKeysCount();
};
