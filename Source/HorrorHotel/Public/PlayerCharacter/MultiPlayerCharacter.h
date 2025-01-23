// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HorrorHotel/TP_TopDown/TP_TopDownCharacter.h"
#include "MultiPlayerCharacter.generated.h"

UCLASS(Blueprintable)
class HORRORHOTEL_API AMultiPlayerCharacter : public ATP_TopDownCharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	// Sets default values for this pawn's properties
	AMultiPlayerCharacter();
	
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	//Collisions events
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CollisionComponent;
};
