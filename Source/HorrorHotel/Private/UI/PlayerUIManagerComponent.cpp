#include "UI/PlayerUIManagerComponent.h"
#include "Blueprint/UserWidget.h"
#include "GameCore/MultiplayerGameStateBase.h"

UPlayerUIManagerComponent::UPlayerUIManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerUIManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	if(AMultiplayerGameStateBase* GameState = GetWorld()->GetGameState<AMultiplayerGameStateBase>())
	{
		GameState->OnKeyCountChanged.AddDynamic(this, &UPlayerUIManagerComponent::UpdateKeyCountUI);
	}
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

void UPlayerUIManagerComponent::UpdateKeyCountUI()
{
	if (AMultiplayerGameStateBase* GameState = GetWorld()->GetGameState<AMultiplayerGameStateBase>())
	{
		int32 KeyCount = GameState->GetKeyCount();
	}        
}


