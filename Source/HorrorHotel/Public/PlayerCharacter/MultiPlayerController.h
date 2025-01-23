//MultiPlayerController.h
#pragma once
#include "CoreMinimal.h"
#include "HorrorHotel/TP_TopDown/TP_TopDownPlayerController.h"
#include "Items/InteractableItem.h"
#include "UI/PlayerUIManagerComponent.h"
#include "MultiPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

UCLASS()
class AMultiPlayerController : public ATP_TopDownPlayerController
{
	GENERATED_BODY()

public:
	AMultiPlayerController();

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SetInteractAction;

	void ShowInteractionWidget(bool bShow);
	void SetInteractionItem(AInteractableItem* InItem);
	
	UFUNCTION(BlueprintCallable)
	void DropItem(int32 ItemIndex);

	UFUNCTION(Server, Reliable)
	void Server_DropItem(int32 ItemIndex, FVector InLocation);

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	/** Input handlers for SetDestination action. */
	virtual void OnInteract();

	UFUNCTION(Server, Reliable)
	void Server_PlayerInteract(AInteractableItem* InItem);

	AInteractableItem* ItemToInteract;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPlayerUIManagerComponent* PlayerUIManagerComponent;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class APickableItem> BP_PickableItemClass;
};
