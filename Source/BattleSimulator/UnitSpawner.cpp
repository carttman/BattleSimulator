// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitSpawner.h"
#include "Unit.h"
// Sets default values
AUnitSpawner::AUnitSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnitSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	// 액터 스폰 파라미터 설정
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	
	for (int i=0; i<100; i++)
	{
		
		FVector v = { SpawnLocation.X + i * 100 % 1000, SpawnLocation.Y + (i / 10) * 100, SpawnLocation.Z + 50};

		GetWorld()->SpawnActor(m_Unit, &v, &SpawnRotation);
	}

}

// Called every frame
void AUnitSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

