// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLELEARN_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Add location
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector platVeloc = FVector(0, 300, 0);

	UPROPERTY(VisibleAnyWhere)
	float distMoved = 0.00;

	UPROPERTY(EditAnywhere, Category="Move Distance")
	int moveDist = 1000;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator rotationVeloc;

	FVector startLoc;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	const bool  ShouldPlatformReturn();

	const float GetDistanceMoved();
};