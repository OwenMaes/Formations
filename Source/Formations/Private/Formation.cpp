// Fill out your copyright notice in the Description page of Project Settings.


#include "Formation.h"

// Sets default values
AFormation::AFormation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFormation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFormation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

