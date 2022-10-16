// Fill out your copyright notice in the Description page of Project Settings.


#include "TestudoFormation.h"

TestudoFormation::TestudoFormation()
{
}

TestudoFormation::~TestudoFormation()
{
}

void TestudoFormation::ChangeInPersonnel(TArray<ACharacter*>& soldiers)
{
	FString text;
	text = "Testudo formation: change in personnel, " + FString::FromInt(soldiers.Num());
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, text);
}

void TestudoFormation::UpdateSoldierPostions(float deltaTime)
{
}
