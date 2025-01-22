#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MultiplayerGameStateBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKeyCountChanged);

UCLASS()
class HORRORHOTEL_API AMultiplayerGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMultiplayerGameStateBase();

	UFUNCTION(BlueprintCallable, Category = "Keys")
	void Addkey();

	UFUNCTION(BlueprintCallable, Category = "Keys")
	int32 GetKeyCount() const {return KeysCount; }

	UFUNCTION(BlueprintCallable, Category = "Keys")
	int32 GetMaxKeys() const { return MaxKeys; }

	//Delegate to request ui updates
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnKeyCountChanged OnKeyCountChanged;
	
protected:
	UPROPERTY(ReplicatedUsing = OnRep_KeyCount, VisibleAnywhere, BlueprintReadWrite, Category = "Keys")
	int32 KeysCount;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int32 MaxKeys;
	
	UFUNCTION()
	void OnRep_KeyCount();
};
