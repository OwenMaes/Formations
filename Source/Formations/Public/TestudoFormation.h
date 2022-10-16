// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IFormation.h"

/**
 * 
 */
class FORMATIONS_API TestudoFormation: public UIFormation
{
public:
	TestudoFormation();
	~TestudoFormation();

	void ChangeInPersonnel(TArray<ACharacter*>& soldiers);
	void UpdateSoldierPostions(float deltaTime);
};
