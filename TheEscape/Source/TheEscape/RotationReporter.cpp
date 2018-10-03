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

	FString ReportName = GetOwner()->GetName();
	FString ReportPosition = GetOwner()->GetTransform().GetLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s is at position %s"),*ReportName,*ReportPosition);





	
}


// Called every frame
void URotationReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

