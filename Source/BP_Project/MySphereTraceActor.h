// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySphereTraceActor.generated.h"

UCLASS()
class BP_PROJECT_API AMySphereTraceActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMySphereTraceActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Custom")
        FHitResult LineTraceInSphere(float Radius, FVector StartPoint, FVector Direction);
};
