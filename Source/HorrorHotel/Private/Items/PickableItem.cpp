#include "HorrorHotel/Public/Items/PickableItem.h"

APickableItem::APickableItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APickableItem::BeginPlay()
{
	Super::BeginPlay();
}

void APickableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Logic for when the item is picked up
void APickableItem::OnPickedUp()
{
	UE_LOG(LogTemp, Warning, TEXT("%s picked up"), *ItemName);
}
