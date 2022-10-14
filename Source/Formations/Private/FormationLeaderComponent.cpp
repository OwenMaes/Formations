// Fill out your copyright notice in the Description page of Project Settings.


#include "FormationLeaderComponent.h"

// Sets default values for this component's properties
UFormationLeaderComponent::UFormationLeaderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UFormationLeaderComponent::RecruitAllInRadius()
{
}

void UFormationLeaderComponent::AddSoldier(ACharacter* soldier)
{
	if (ArrayOfSoldiers.Contains(soldier))
		return;

	ArrayOfSoldiers.Add(soldier);
	ChangeInPersonnel();
}

void UFormationLeaderComponent::RemoveSoldier(ACharacter* soldier)
{
	if (!ArrayOfSoldiers.Contains(soldier))
		return;

	ArrayOfSoldiers.Remove(soldier);
	ChangeInPersonnel();
}


// Called when the game starts
void UFormationLeaderComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UFormationLeaderComponent::ChangeInPersonnel()
{
	switch (FormationType)
	{
	case EFormationType::BASIC:
		break;
	case EFormationType::TESTUDO:
		AdjustShieldWall();
		break;
	case EFormationType::ORBIS:
		break;
	default:
		break;
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Emerald, FString::FromInt(ArrayOfSoldiers.Num()));
}

void UFormationLeaderComponent::AdjustShieldWall()
{
	int nrOfSoldiers = ArrayOfSoldiers.Num();
	int minSoldiersRequired = 4;

	if (nrOfSoldiers < minSoldiersRequired)
		return;

	//Calculate rows and cols of shield wall, closest to a square possible
	int rows = floor(sqrt(nrOfSoldiers));
	int cols = floor(nrOfSoldiers / rows);
	int remains = nrOfSoldiers - (rows + cols);
}

// Called every frame
void UFormationLeaderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

