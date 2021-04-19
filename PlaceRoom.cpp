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

void APlaceRoom::PlaceXplusDoor()
{
	bool spn = false;
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	for (int j = 0; j < 3; j++)
	{
		if (Location.X + 2420  == NeighboursX[j])
		{
			spn = true;
			break;
		}
	}
	if (spn != true)
	{
		Location.X += 1260 ;
		Rotation.Yaw += 90;
		SetActorLocation(Location);
		SetActorRotation(Rotation);
		GetWorld()->SpawnActor<AActor>(Door, GetActorLocation(), GetActorRotation());
		Location.X -= 1260 ;
		Rotation.Yaw -= 90;
		SetActorLocation(Location);
		SetActorRotation(Rotation);
	}
}

void APlaceRoom::PlaceYplusDoor()
{
	bool spn = false;
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	for (int j = 0; j < 3; j++)
	{
		if (Location.Y + 2420  == NeighboursY[j])
		{
			spn = true;
			break;
		}
	}
	if (spn != true)
	{
		Location.Y += 1200 ;
		//Rotation.Yaw += 90;
		SetActorLocation(Location);
		//SetActorRotation(Rotation);
		GetWorld()->SpawnActor<AActor>(Door, GetActorLocation(), GetActorRotation());
		Location.Y -= 1200 ;
		//Rotation.Yaw -= 90;
		SetActorLocation(Location);
		//SetActorRotation(Rotation);
	}
}
void APlaceRoom::PlaceXminusDoor()
{
	bool spn = false;
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	for (int j = 0; j < 3; j++)
	{
		if (Location.X - 2420  == NeighboursX[j])
		{
			spn = true;
			break;
		}
	}
	if (spn != true)
	{
		Location.X -= 1200 ;
		Rotation.Yaw += 90;
		SetActorLocation(Location);
		SetActorRotation(Rotation);
		GetWorld()->SpawnActor<AActor>(Door, GetActorLocation(), GetActorRotation());
		Location.X += 1200 ;
		Rotation.Yaw -= 90;
		SetActorLocation(Location);
		SetActorRotation(Rotation);
	}
}
void APlaceRoom::PlaceYminusDoor()
{
	bool spn = false;
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	for (int j = 0; j < 3; j++)
	{
		if (Location.Y - 2420  == NeighboursY[j])
		{
			spn = true;
			break;
		}
	}
	if (spn != true)
	{
		Location.Y -= 1250 ;
		//Rotation.Yaw += 90;
		SetActorLocation(Location);
		//SetActorRotation(Rotation);
		GetWorld()->SpawnActor<AActor>(Door, GetActorLocation(), GetActorRotation());
		Location.Y += 1250 ;
		//Rotation.Yaw -= 90;
		SetActorLocation(Location);
		//SetActorRotation(Rotation);
	}
}

// Called when the game starts or when spawned
void APlaceRoom::BeginPlay()
{
	Super::BeginPlay();
	srand(time(0));
	GetWorld()->SpawnActor<AActor>(StartRoom, GetActorLocation(), GetActorRotation());
	SpawnedRoomsX[0] = GetActorLocation().X;
	SpawnedRoomsY[0] = GetActorLocation().Y;
		for (int i = 1; i < 10; i++) {
			bool x = false, y = false, mx = false, my = false;
			//FVector Location = GetActorLocation();
			const FRotator Rotation = GetActorRotation();
			FVector NewLocation = GetActorLocation();
			int ConX = rand() % 2;
			int ConY = rand() % 2;
			for (int loc = 0; loc < 20; loc++)
			{
				if (NewLocation.Y + 2420  == SpawnedRoomsY[loc])
				{
					y = true;
				}
				if (NewLocation.Y - 2420  == SpawnedRoomsY[loc])
				{
					my = true;
				}
				if (NewLocation.X + 2420  == SpawnedRoomsX[loc])
				{
					x = true;
				}
				if (NewLocation.X - 2420  == SpawnedRoomsX[loc])
				{
					mx = true;
				}
			}
					if ((ConX == 0) && (x == false))
					{
						PlaceYminusDoor();
						PlaceXminusDoor();
						PlaceYplusDoor();
						NewLocation.X += 2420 ;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						SpawnedRoomsX[i] = NewLocation.X;
						NeighboursX[1] = NewLocation.X - 2420;
						NeighboursY[0] = 0;
						NeighboursY[1] = 0;
						x = true;
					}
					if ((ConX == 1) && (mx == false))
					{
						PlaceYminusDoor();
						PlaceYplusDoor();
						PlaceXplusDoor();
						NewLocation.X -= 2420 ;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						SpawnedRoomsX[i] = NewLocation.X;
						NeighboursX[0] = NewLocation.X + 2420;
						NeighboursY[0] = 0;
						NeighboursY[1] = 0;
						mx = true;
					}
					
					if (ConY == 0 && y == false)
					{
						PlaceYminusDoor();
						PlaceXminusDoor();
						PlaceXplusDoor();
						NewLocation.Y += 2420 ;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						SpawnedRoomsY[i] = NewLocation.Y;
						NeighboursY[1] = NewLocation.Y - 2420;
						NeighboursX[0] = 0;
						NeighboursX[1] = 0;
						y = true;
					}
					if (ConY == 1 && my == false)
					{
						PlaceXminusDoor();
						PlaceYplusDoor();
						PlaceXplusDoor();
						NewLocation.Y -= 2420 ;
						SetActorLocation(NewLocation);
						GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, Rotation);
						SpawnedRoomsY[i] = NewLocation.Y;
						NeighboursY[0] = NewLocation.Y + 2420;
						NeighboursX[0] = 0;
						NeighboursX[1] = 0;
						my = true;
					}
					


		}
		//GetWorld()->SpawnActor<AActor>(BossRoom, GetActorLocation(), GetActorRotation());
		if (NeighboursY[9] + 2420 != 0)
		{
			PlaceYminusDoor();
			//PlaceXminusDoor();
			PlaceXplusDoor();
		}
		if (NeighboursY[9] - 2420 != 0) {
			//PlaceXminusDoor();
			PlaceYplusDoor();
			PlaceXplusDoor();
		}
		FVector NewLocation = GetActorLocation();
		const FRotator Rotation = GetActorRotation();
		NewLocation.X -= 2420;
		SetActorLocation(NewLocation);
		GetWorld()->SpawnActor<AActor>(BossRoom, NewLocation, Rotation);
}

// Called every frame
void APlaceRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}






