#include "UI/PlayerUIManagerComponent.h"
#include "Blueprint/UserWidget.h"

UPlayerUIManagerComponent::UPlayerUIManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerUIManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerUIManagerComponent::InitializeUI(APlayerController* PlayerController)
{
	if (PlayerController && InteractionWidgetClass)
	{
		InteractionWidgetInstance = CreateWidget<UUserWidget>(PlayerController, InteractionWidgetClass);
		if (InteractionWidgetInstance)
		{
			InteractionWidgetInstance->AddToViewport();
			InteractionWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UPlayerUIManagerComponent::ShowInteractionWidget(bool bShow)
{
	if (InteractionWidgetInstance)
	{
		InteractionWidgetInstance->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}

