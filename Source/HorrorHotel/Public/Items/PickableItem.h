#pragma once

#include "CoreMinimal.h"
#include "Items/InteractableItem.h"
#include "PickableItem.generated.h"

UCLASS()
class HORRORHOTEL_API APickableItem : public AInteractableItem
{
	GENERATED_BODY()

public:
	APickableItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (ExposeOnSpawn = "true"))
	int32 ItemIndex;
	
	virtual void OnInteraction() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item")
	void ItemPickedUpEvent();

};
