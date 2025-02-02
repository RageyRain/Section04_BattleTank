// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"
#include "Tank.generated.h" //Must be at bottom

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	public:
		//Called by the engine when actor damage is dealth
		virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
		
		//Returns current health as a percentage oif starting health, between 0 and 1
		UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealthPercent() const;

		UPROPERTY(BlueprintAssignable)
		FTankDelegate OnTankDeath;

	private:
		// Sets default values for this pawn's properties
		ATank();

		virtual void BeginPlay() override;

		UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingHealth = 100;

		UPROPERTY(VisibleAnywhere, Category = "Health")
		int32 CurrentHealth; //Initialised in BeginPlay
};
