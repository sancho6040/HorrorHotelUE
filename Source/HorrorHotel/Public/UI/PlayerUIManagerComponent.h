// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/Templates/SubclassOf.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "PlayerUIManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HORRORHOTEL_API UPlayerUIManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPlayerUIManagerComponent();

	void InitializeUI(APlayerController* PlayerController);

	// show/hide the interaction widget
	void ShowInteractionWidget(bool bShow);

	void UpdateKeyCountUI();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InteractionWidgetClass;

	UPROPERTY()
	UUserWidget* InteractionWidgetInstance;
};
