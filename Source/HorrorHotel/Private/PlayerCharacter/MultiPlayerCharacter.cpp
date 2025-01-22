#include "PlayerCharacter/MultiPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacter/MultiPlayerController.h"
#include "Items/KeyItem.h"

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

void AMultiPlayerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        if (OtherActor->IsA(AKeyItem::StaticClass()))
        {
            AMultiPlayerController* PC = Cast<AMultiPlayerController>(GetController());
            if (PC)
            {
                PC->ShowInteractionWidget(true);
            }
        }
    }
}

void AMultiPlayerCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor != this)
    {
        if (OtherActor->IsA(AKeyItem::StaticClass()))
        {
            AMultiPlayerController* PC = Cast<AMultiPlayerController>(GetController());
            if (PC)
            {
                PC->ShowInteractionWidget(false);
            }
        }
    }
}
