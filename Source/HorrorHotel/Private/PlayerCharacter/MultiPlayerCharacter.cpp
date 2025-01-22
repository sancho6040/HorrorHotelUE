#include "PlayerCharacter/MultiPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Items/InteractableItem.h"
#include "PlayerCharacter/MultiPlayerController.h"

AMultiPlayerCharacter::AMultiPlayerCharacter()
{
	CollisionComponent = GetCapsuleComponent();

	// Configure additional components for this character
	CollisionComponent->InitCapsuleSize(42.f, 96.0f);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AMultiPlayerCharacter::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AMultiPlayerCharacter::OnOverlapEnd);
}

void AMultiPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMultiPlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMultiPlayerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                           const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		AInteractableItem* KeyItem = Cast<AInteractableItem>(OtherActor);
		AMultiPlayerController* PlayerController = Cast<AMultiPlayerController>(GetController());
		if (KeyItem && PlayerController)
		{
			PlayerController->ShowInteractionWidget(true);
			PlayerController->SetInteractionItem(KeyItem);
		}
	}
}

void AMultiPlayerCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this)
	{
		if (OtherActor->IsA(AInteractableItem::StaticClass()))
		{
			AMultiPlayerController* PlayerController = Cast<AMultiPlayerController>(GetController());
			if (PlayerController)
			{
				PlayerController->ShowInteractionWidget(false);
				PlayerController->SetInteractionItem(nullptr);
			}
		}
	}
}
