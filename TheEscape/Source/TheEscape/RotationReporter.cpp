// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationReporter.h"

#include "GameFramework/Actor.h"
#include "Math/TransformNonVectorized.h"



// Sets default values for this component's properties
URotationReporter::URotationReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotationReporter::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	ObjectToCollideWith = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void URotationReporter::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void URotationReporter::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

// Called every frame
void URotationReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate->IsOverlappingActor(ObjectToCollideWith))
	{
		OpenDoor();
		LastOpenTime = GetWorld()->GetTimeSeconds();
	}

}

