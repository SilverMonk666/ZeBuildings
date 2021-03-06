// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/TriggerVolume.h"
#include "MoveDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEESCAPE_API UMoveDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = -90.f;
	
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		float DoorClosedDelay = 1.f;

		float LastDoorOpenTime;

		AActor* ObjectToCollideWith;
		AActor* Owner;//Owning Door


		
	
};
