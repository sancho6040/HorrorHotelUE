#include "..\..\Public\Items\InteractableItem.h"

#include "Net/UnrealNetwork.h"

AInteractableItem::AInteractableItem()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void AInteractableItem::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Logic for when the item is picked up
void AInteractableItem::OnInteraction()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("door interaction"));

	UE_LOG(LogTemp, Warning, TEXT("%s picked up"), *ItemName);
}

void AInteractableItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInteractableItem, ItemName);
}
