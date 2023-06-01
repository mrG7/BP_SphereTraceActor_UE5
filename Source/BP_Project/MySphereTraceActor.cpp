// Fill out your copyright notice in the Description page of Project Settings.

#include "MySphereTraceActor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMySphereTraceActor::AMySphereTraceActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMySphereTraceActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMySphereTraceActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

FHitResult AMySphereTraceActor::LineTraceInSphere(float Radius, FVector StartPoint, FVector Direction)
{
    FHitResult HitResult;

    FVector EndPoint = StartPoint + (Direction.GetSafeNormal() * Radius);

    FCollisionQueryParams TraceParams;
    TraceParams.bTraceComplex = true;
    TraceParams.bReturnPhysicalMaterial = false;

    AActor* ActorToIgnore = nullptr;
    TraceParams.AddIgnoredActor(ActorToIgnore);

    GetWorld()->LineTraceSingleByChannel(
        HitResult,
        StartPoint,
        EndPoint,
        ECC_Visibility,
        TraceParams
    );

    DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Red, false, 1, 0, 1);

    return HitResult;
}
