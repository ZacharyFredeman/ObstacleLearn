// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	startLoc = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime){
	//Move platform foward

	//reverse platform direct if moved wanted distance	
	if(ShouldPlatformReturn()){
		FVector moveDirect = platVeloc.GetSafeNormal();
		platVeloc = -platVeloc;
		startLoc = startLoc + moveDirect * moveDist;
		SetActorLocation(startLoc);

		// float overShoot = distMoved - moveDist;
		// FString objName = GetName();
		// UE_LOG(LogTemp, Display, TEXT("%s Move Distance: %f"), *objName, overShoot);
	}
	else{
		//get location, add vect to location
		FVector curLoc = GetActorLocation();
		curLoc += (platVeloc * DeltaTime);
		SetActorLocation(curLoc);
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime){
	AddActorLocalRotation(rotationVeloc * DeltaTime);
}

const bool AMovingPlatform::ShouldPlatformReturn(){
	return(GetDistanceMoved()  > moveDist);
}

const float AMovingPlatform::GetDistanceMoved(){
	distMoved = FVector :: Dist(startLoc, GetActorLocation());
	return(distMoved);
}
