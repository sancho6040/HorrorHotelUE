#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableItem.generated.h"

UCLASS()
class HORRORHOTEL_API APickableItem : public AActor
{
	GENERATED_BODY()
    
public: 
	APickableItem();

protected:
	virtual void BeginPlay() override;

public: 
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pickable")
	virtual void OnPickedUp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickable")
	FString ItemName;
};