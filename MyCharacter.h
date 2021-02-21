// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class ROGUELIKEGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	
	//ќбъ€вили камеру персонажа
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FPCamera;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;


	//ќбъ€вили метод движени€ вперед-назад
	void MoveForward(float Axis);
	//ќбъ€вили метод движени€ вправо-влево
	void MoveRight(float Axis);
	//ќбъ€вили методы прыжков
	void Jump();
	void StopJumping();


	// ќбъ€вл€ем переменную смерти
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDead;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
