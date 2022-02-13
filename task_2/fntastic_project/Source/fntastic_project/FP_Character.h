// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "FP_Character.generated.h"

UCLASS()
class FNTASTIC_PROJECT_API AFP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFP_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LookRightLeft(float axisvalue);
	void LookUpDown(float axisvalue);
	void MoveForwardBackward(float axisvalue);
	void MoveRightLeft(float axisvalue);

	UPROPERTY(EditAnywhere, Category="Components")
	UCameraComponent*	Camera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
