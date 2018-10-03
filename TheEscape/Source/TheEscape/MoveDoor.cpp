// Fill out your copyright notice in the Description page of Project Settings.



#include "MoveDoor.h"
#include "Math/TransformNonVectorized.h"




// Sets default values for this component's properties
UMoveDoor::UMoveDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveDoor::BeginPlay()
{
	Super::BeginPlay();

	ObjectToCollideWith = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void UMoveDoor::OpenDoor()
{
	//Find the Owning actor
	AActor* Owner = GetOwner();

	//Create a rotation
	FRotator NewRotation = FRotator(0.f, 80.f, 0.f);
	//Set the door Rotation
	Owner->SetActorRotation(NewRotation);

}


// Called every frame
void UMoveDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PressurePlate->IsOverlappingActor(ObjectToCollideWith))
	{
		OpenDoor();
	}
}

