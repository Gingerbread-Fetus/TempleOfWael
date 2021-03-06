// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEMPLEOFWAEL_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void OpenDoor(float DeltaTime);
	virtual void CloseDoor(float DeltaTime);
	void FindAudioComponent();
	float TotalMassOfActors() const;

	bool OpenDoorSound = false;
	bool CloseDoorSound = true;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 2.f;
	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 0.5f;
	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
	float MassToOpen = 50.f;
	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;

	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.f;
};
