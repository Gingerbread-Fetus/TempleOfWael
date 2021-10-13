// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEMPLEOFWAEL_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
private:
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();
	FHitResult GetFirstPhysicsBodyInReach() const;
	// Return The Line Trace End.
	FVector GetPlayersReach() const;
	// Get Players Position In World.
	FVector GetPlayersWorldPos() const;
};
