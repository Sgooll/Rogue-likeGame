// Fill out your copyright notice in the Description page of Project Settings.

#include "PlaceRoom.h"
#include "Engine/World.h"
#include "ctime"

// Sets default values
APlaceRoom::APlaceRoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlaceRoom::BeginPlay()
{
	Super::BeginPlay();
	srand(time(0));
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetActorLocation(), GetActorRotation());
		for (int i = 0; i < 10; i++) {
			bool x = false, y = false, mx = false, my = false;
			const FVector Location = GetActorLocation();
			const FRotator Rotation = GetActorRotation();
			FVector NewLocation = GetActorLocation();
			int ConX = rand() % 4;
			int ConY = rand() % 4;
			for (int loc = 0; loc < 10; loc++)
			{
				if (NewLocation.Y + 2425.0f == SpawnedRoomsY[loc])
					y = true;
				if (NewLocation.Y - 2425.0f == SpawnedRoomsY[loc])
					my = true;
				if (NewLocation.X + 2425.0f == SpawnedRoomsX[loc])
					x = true;
				if (NewLocation.X - 2425.0f == SpawnedRoomsX[loc])
					mx = true;
			}
					if ((ConX == 0) && (x == false))
					{
						NewLocation.X += 2425.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						x = true;
					}
					if ((ConX == 1) && (mx == false))
					{
						NewLocation.X -= 2425.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						mx = true;
					}
					if (ConX == 2 && (x == false) && (mx == false))
					{
						NewLocation.X += 2425.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						NewLocation.X -= 4850.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						x = true;
						mx = true;
					}
					if (ConX == 3) continue;
					if (ConY == 0 && y == false)
					{
						NewLocation.Y += 2425.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						y = true;
					}
					if (ConY == 1 && my == false)
					{
						NewLocation.Y -= 2425.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						my = true;
					}
					if (ConY == 2  && y == false && my == false)
					{
						NewLocation.Y += 2425.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						NewLocation.Y -= 4850.0f;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						y = true;
						my = true;
					}
					if (ConY == 3) continue;
					SpawnedRoomsY[i] = NewLocation.Y;
					SpawnedRoomsX[i] = NewLocation.X;
				

		}

}

// Called every frame
void APlaceRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

