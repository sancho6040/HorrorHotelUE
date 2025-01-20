#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MultiplayerGameStateBase.generated.h"

UCLASS()
class HORRORHOTEL_API AMultiplayerGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMultiplayerGameStateBase();

	UFUNCTION(BlueprintCallable, Category = "Keys")
	void Addkey();

	UFUNCTION(BlueprintCallable, Category = "Keys")
	int32 GetKeyCount() const;

protected:
	UPROPERTY(ReplicatedUsing = OnRep_KeyCount, VisibleAnywhere, BlueprintReadWrite, Category = "Keys")
	int32 KeysCount;

	UFUNCTION()
	void OnRep_KeyCount();
};
