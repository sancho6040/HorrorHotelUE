#pragma once

#include "CoreMinimal.h"
#include "InteractableItem.h"
#include "InteractableDoor.generated.h"

UCLASS()
class HORRORHOTEL_API AInteractableDoor : public AInteractableItem
{
	GENERATED_BODY()

public:
	AInteractableDoor();

	virtual void OnInteraction() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void OpenDoorEvent();
};
