#pragma once

#include "CoreMinimal.h"
#include "HorrorHotel/TP_TopDown/TP_TopDownPlayerController.h"
#include "Items/PickableItem.h"
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
	void SetInteractionItem(APickableItem* InItem);

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	/** Input handlers for SetDestination action. */
	virtual void OnInteract();

	APickableItem* ItemToInteract;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPlayerUIManagerComponent* PlayerUIManagerComponent;
};
