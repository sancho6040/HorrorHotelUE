#include "Items/PickableItem.h"

APickableItem::APickableItem()
{
	ItemName = "Pickable Item";
}

void APickableItem::OnInteraction()
{
	Super::OnInteraction();
	Destroy();
}