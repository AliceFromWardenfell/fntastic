// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Character.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFP_Character::AFP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFP_Character::LookRightLeft(float axisvalue)
{
	this->AddControllerYawInput(axisvalue);
}

void AFP_Character::LookUpDown(float axisvalue)
{
	UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), axisvalue)
	if (Controller->IsLocalPlayerController())
		UE_LOG(LogTemp, Warning, TEXT("TRUE"))
	else
		UE_LOG(LogTemp, Warning, TEXT("False"))
	this->AddControllerPitchInput(axisvalue);
}

void AFP_Character::MoveForwardBackward(float axisvalue)
{
	this->AddMovementInput(this->GetActorForwardVector() * axisvalue);
}

void AFP_Character::MoveRightLeft(float axisvalue)
{
	this->AddMovementInput(this->GetActorRightVector() * axisvalue);
}

// Called every frame
void AFP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &AFP_Character::LookUpDown);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AFP_Character::LookRightLeft);
	PlayerInputComponent->BindAxis(TEXT("ForwardBackward"),this, &AFP_Character::MoveForwardBackward);
	PlayerInputComponent->BindAxis(TEXT("RightLeft"), this, &AFP_Character::MoveRightLeft);

}

