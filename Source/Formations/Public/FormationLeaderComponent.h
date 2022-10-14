// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FormationLeaderComponent.generated.h"

UENUM(BlueprintType)
enum class EFormationType : uint8 {
	BASIC = 0 UMETA(DisplayName = "Basic formation"),
	TESTUDO = 1 UMETA(DisplayName = "Testudo (Shield wall)"),
	ORBIS = 2 UMETA(DisplayName = "Orbis (Shield circle)"),

};

UENUM(BlueprintType)
enum class EFormationCommand : uint8 {
	STAND = 0 UMETA(DisplayName = "Stand"),
	ADVANCE = 1 UMETA(DisplayName = "Advance"),
	SHIFT = 2 UMETA(DisplayName = "Shift"),

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORMATIONS_API UFormationLeaderComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFormationLeaderComponent();

	UFUNCTION(BlueprintCallable, Category = "Legion")
		void RecruitAllInRadius();
	UFUNCTION(BlueprintCallable, Category = "Legion")
		void AddSoldier(ACharacter* soldier);
	UFUNCTION(BlueprintCallable, Category = "Legion")
		void RemoveSoldier(ACharacter* soldier);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TArray<ACharacter*> ArrayOfSoldiers;
	EFormationType FormationType = EFormationType::TESTUDO;
	EFormationCommand FormationCommand = EFormationCommand::STAND;

	void ChangeInPersonnel();
	void AdjustShieldWall();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
