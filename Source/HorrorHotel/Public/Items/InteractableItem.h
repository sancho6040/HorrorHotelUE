#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableItem.generated.h"

UCLASS()
class HORRORHOTEL_API AInteractableItem : public AActor
{
	GENERATED_BODY()
    
public: 
	AInteractableItem();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Pickable")
	FString ItemName;

	UFUNCTION(BlueprintCallable, Category = "Pickable")
	virtual void OnInteraction();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;
};